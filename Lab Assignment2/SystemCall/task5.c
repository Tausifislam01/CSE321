#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
pid_t child;
pid_t granchild1;
pid_t granchild2;
pid_t granchild3;

child = fork();
if (child ==0){
printf("Child Process ID: %d\n", getpid());
granchild1 = fork();
if (granchild1 ==0){
printf("Granchild Process ID: %d\n", getpid());

return 0;
}

granchild2 = fork();
if (granchild2 ==0){
printf("Granchild Process ID: %d\n", getpid());

return 0;
}
granchild3 = fork();
if (granchild3==0){
printf("Granchild Process ID: %d\n", getpid());

return 0;
}



}
else if (child>0){
printf("Parent Process ID: %d\n", getpid());
wait(NULL);
}
return 0;
}
