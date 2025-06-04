#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

pid_t pid, granchild_pid;

pid = fork();
if (pid==0){
granchild_pid = fork();
if (granchild_pid==0){
printf("I am grandchild\n");
}
else if (granchild_pid>0){
wait(NULL);
printf("I am child\n");
}
}
else if (pid>0){
wait(NULL);
printf("I am parent\n");
}
return 0;
}
