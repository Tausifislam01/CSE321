#include <stdio.h>
#include <pthread.h>
#include <string.h>

int values[3];
int idx = 0;
void* calc(void* arg){
char* name = (char*)arg;
int sum = 0;

for (int i = 0; i<strlen(name);i++){
sum+=name[i];
}


values[idx] = sum;
idx++;
}

void* res(void* arg){
if (values[0]==values[1] && values[1]==values[2]){
printf("Youreka\n");
}

else if (values[0]==values[1] || values[1]==values[2] || values[0]==values[2]){
printf("Miracle\n");
}
else{
printf("Hasta la vista\n");
}

}



int main(){
pthread_t thrd[4];
char* names[3] = {"Tausif", "Tahmid", "Taufiq"};

for (int i =0; i<3; i++){
pthread_create(&thrd[i], NULL, calc, names[i]);
pthread_join(thrd[i], NULL);
}
pthread_create(&thrd[3], NULL, res, NULL);
pthread_join(thrd[3], NULL);
}
