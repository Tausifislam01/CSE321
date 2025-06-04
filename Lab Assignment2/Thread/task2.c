#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* threadF(void* arg){
int t_id = *(int*)arg;

for (int i = 0; i<5; i++){
printf("Thread-%d prints %d\n", t_id, (t_id*4)+(i+1));
}

return NULL;
}

int main(){
pthread_t thrd[5];
int thrd_id[5];

for (int i=0; i<5;i++){
thrd_id[i]=i;
pthread_create(&thrd[i], NULL, threadF, &thrd_id[i]);
pthread_join(thrd[i],NULL);
}

return 0;
}
