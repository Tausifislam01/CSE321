#include <stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>


struct data {
char sel[100];
int b;
};

int main(){

struct data account;
char msg[100] = "Thank you for your service";
int fd[2];
pipe(fd);
void* smem;
char inp;
printf("Provide you input from given options: \n");
printf("1.Type 'a' to add money\n");
printf("2. Type 'w' to withdraw money\n");
printf("3. TYpe 'c' to check balance\n");
scanf("%c", &inp);
printf("You selected: %c\n", inp);
account.sel[0] = inp;
account.sel[1] = '\0';
account.b = 1000;

int memid = shmget((key_t)101, sizeof(struct data), 0666 |IPC_CREAT);
smem = shmat(memid, NULL, 0);
memcpy(smem, &account, sizeof(struct data));

pid_t pid = fork();
if (pid == 0){
struct data *s_account = (struct data*)smem;
if (s_account->sel[0]=='a'){
printf("Enter amount to be added: \n");
int dep;
scanf("%d", &dep);

if (dep>0){
s_account->b += dep;
printf("Balnced added succesfully\n");
printf("Updated balance after addition: %d\n", s_account -> b);
}
else{
printf("Adding failed, Invalid amount\n");
}
}
else if (s_account->sel[0]=='w'){
printf("Enter amount to withdrawn: \n");
int withdraw;
scanf("%d", &withdraw);
if (withdraw>0 && withdraw <=s_account->b){
s_account->b-=withdraw;
printf("Balnced withdrawn succesfully\n");
printf("Updated balance after withdrawal: %d\n", s_account ->b);
}
else{
printf("Withdrawal failed, Invalid amount\n");
}
}
else if (s_account->sel[0]=='c'){
printf("Your current balance is: %d\n", s_account -> b);
}
else{
printf("Invalid selection\n");
}

close(fd[0]);
write(fd[1], msg, sizeof(msg));
close(fd[1]);
}
else{
wait(NULL);
close(fd[1]);
read(fd[0], msg, sizeof(msg));
printf("%s\n", msg);
close(fd[0]);
shmctl(memid,IPC_RMID,NULL);
}

}
