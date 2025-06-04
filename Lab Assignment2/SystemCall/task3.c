#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

int first_pid = getpid();
pid_t a, b,c;
int p = 1;

a = fork();
p++;
if (a==0){
	if (getpid()%2!=0){
	p++;
	if (fork() ==0){;
	exit(0);}
	}
}


b = fork();
p++;
if (b==0){
	if (getpid()%2!=0){
	p++;
	if (fork() ==0){;
	exit(0);}
	}
}



c = fork();
p++;
if (c==0){
	if (getpid()%2!=0){
	p++;
	if (fork() ==0){;
	exit(0);}
	}
}

wait(NULL);
if (getpid() == first_pid){

printf("Total processes created: %d\n", p);
}

}
