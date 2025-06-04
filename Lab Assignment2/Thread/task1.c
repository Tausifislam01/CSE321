#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* threadF(void* arg){
int threadn = *(int*)arg;
printf("thread-%d running\n", threadn);
sleep(2);
printf("thread-%d closed\n", threadn);
return NULL;
}

int main(){
int thr_num[5];
pthread_t thr[5];

for (int i=0; i<5;i++){
thr_num[i]=i+1;
pthread_create(&thr[i],NULL,threadF, &thr_num[i]);
pthread_join(thr[i],NULL);
}
return 0;
}
