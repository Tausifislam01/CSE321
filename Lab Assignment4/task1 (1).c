#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> 

#define MAX 10     
#define BUFLEN 6     
#define NUMTHREAD 2  

void *producer(void *id);
void *consumer(void *id);

char buffer[BUFLEN];    
char source[BUFLEN + 1] = "abcdef"; 
int bufferCount = 0;    
int prodIndex = 0;      
int consIndex = 0;     
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t bufferNotEmpty = PTHREAD_COND_INITIALIZER;
pthread_cond_t bufferNotFull = PTHREAD_COND_INITIALIZER;

int main() {
    pthread_t threads[NUMTHREAD];
    int thread_ids[NUMTHREAD] = {0, 1};

    pthread_create(&threads[0], NULL, producer, &thread_ids[0]);
    sleep(1);
    pthread_create(&threads[1], NULL, consumer, &thread_ids[1]);

    
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    return 0;
}

void *producer(void *id) {
    for (int count = 0; count < MAX; count++) {
        pthread_mutex_lock(&mutex);

        while (bufferCount == BUFLEN) { 
            pthread_cond_wait(&bufferNotFull, &mutex);
        }
        buffer[prodIndex % BUFLEN] = source[prodIndex % BUFLEN];
        printf("%d produced %c by Thread %d\n", prodIndex, source[prodIndex % BUFLEN], *(int *)id);
        prodIndex++;
        bufferCount++;

        pthread_cond_signal(&bufferNotEmpty); 
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void *consumer(void *id) {
    for (int count = 0; count < MAX; count++) {
        pthread_mutex_lock(&mutex);

        while (bufferCount == 0) { 
            pthread_cond_wait(&bufferNotEmpty, &mutex);
        }
        printf("%d consumed %c by Thread %d\n", consIndex, buffer[consIndex % BUFLEN], *(int *)id);
        consIndex++;
        bufferCount--;

        pthread_cond_signal(&bufferNotFull); 
        pthread_mutex_unlock(&mutex);
        sleep(2); 
    }
    return NULL;
}

