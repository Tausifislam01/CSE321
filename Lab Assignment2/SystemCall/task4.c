#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char*argv[]){
int count = argc-1;

pid_t pid = fork();
if (pid==0){
execv("./sort", argv);
} 
else if (pid>0){
wait(NULL);
execv("./oddeven", argv);
}
return 0;
}
