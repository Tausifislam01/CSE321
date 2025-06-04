#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


struct msg {
long int type;
char txt[6];
};

int main() {
char workspace[149];
printf("Please enter the workspace name:\n");
scanf("%s", workspace);

int qid = msgget((key_t)12, 0666 | IPC_CREAT);

if (strcmp(workspace, "cse321") == 0) {
struct msg send_msg;
struct msg receive_msg;
send_msg.type = 2;
strcpy(send_msg.txt, workspace);

int s_status = msgsnd(qid, (void *)&send_msg, sizeof(send_msg.txt), 0);
printf("Workspace name sent to OTP generator from login: %s\n", workspace);

pid_t c_pid = fork();

if (c_pid == 0) {
pid_t otp = getpid();
int r_status = msgrcv(qid, (void*)&receive_msg, sizeof(receive_msg.txt), 2, IPC_NOWAIT);

printf("OTP generator received workspace name from login: %s\n", receive_msg.txt);
   
send_msg.type = 3;
snprintf(send_msg.txt, sizeof(send_msg.txt), "%d", otp);
int s_status2 = msgsnd(qid, (void *)&send_msg, sizeof(send_msg.txt), 0);
printf("OTP sent to login from OTP generator: %s\n", send_msg.txt);

struct msg x, y;
x.type = 4;
snprintf(x.txt, sizeof(x.txt), "%d", otp);
int s_status3 = msgsnd(qid, (void *)&x, sizeof(x.txt), 0);
printf("OTP sent to mail from OTP generator: %s\n", x.txt);

pid_t m_pid = fork();

if (m_pid == 0) {
int m_status = msgrcv(qid, (void*)&y, sizeof(y.txt), 4, IPC_NOWAIT);
printf("Mail received OTP from OTP generator: %s\n", y.txt);

struct msg l_msg;
l_msg.type = 5;
strcpy(l_msg.txt, y.txt);
int s_status4 = msgsnd(qid, (void *)&l_msg, sizeof(l_msg.txt), 0);
printf("OTP sent to log in from mail: %s\n", l_msg.txt);
}
else{
wait(NULL);
exit(0);
}
} 
else {
wait(NULL);
int r_status2 = msgrcv(qid, (void*)&receive_msg, sizeof(receive_msg.txt), 3, IPC_NOWAIT);
printf("Log in received OTP from OTP generator: %s\n", receive_msg.txt);

struct msg otp_msg;
int r_status3 = msgrcv(qid, (void*)&otp_msg, sizeof(otp_msg.txt), 5, IPC_NOWAIT);
printf("Log in received OTP from mail: %s\n", otp_msg.txt);

if (strcmp(receive_msg.txt, otp_msg.txt) == 0) {
printf("OTP Verified\n");
} else {
printf("OTP Incorrect\n");
}
msgctl(qid, IPC_RMID, 0);
}
} else {
printf("Invalid workspace name\n");
}
}


