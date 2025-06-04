#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxCrops 5         // Maximum crops a Farmer can produce or a ShopOwner can take
#define warehouseSize 5    // Size of the warehouse

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize] = {'R', 'W', 'P', 'S', 'M'}; // Indicating room for different crops
char warehouse[warehouseSize] = {'N', 'N', 'N', 'N', 'N'}; // Initially all rooms are empty
pthread_mutex_t mutex;

void *Farmer(void *far) {
    int id = *((int *)far);
    for (int i = 0; i < MaxCrops; i++) {
        sem_wait(&empty);              
        pthread_mutex_lock(&mutex);   
        warehouse[in] = crops[in];
        printf("Farmer %d: Insert crop %c at %d\n", id, crops[in], in);
        in = (in + 1) % warehouseSize;

        printf("Current Warehouse: ");
        for (int j = 0; j < warehouseSize; j++) {
            printf("%c ", warehouse[j]);
        }
        printf("\n");
        pthread_mutex_unlock(&mutex); 
        sem_post(&full);              
    }
    pthread_exit(NULL);
}

void *ShopOwner(void *sho) {
    int id = *((int *)sho);
    for (int i = 0; i < MaxCrops; i++) {
        sem_wait(&full);            
        pthread_mutex_lock(&mutex);   
        char crop = warehouse[out];
        warehouse[out] = 'N';
        printf("Shop Owner %d: Remove crop %c from %d\n", id, crop, out);
        out = (out + 1) % warehouseSize;

        printf("Current Warehouse: ");
        for (int j = 0; j < warehouseSize; j++) {
            printf("%c ", warehouse[j]);
        }
        printf("\n");

        pthread_mutex_unlock(&mutex); 
        sem_post(&empty);             
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t Far[5], Sho[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, warehouseSize); // When the warehouse is full, threads will wait
    sem_init(&full, 0, 0);              // When the warehouse is empty, threads will wait

    int ids[5] = {1, 2, 3, 4, 5}; 
    for (int i = 0; i < 5; i++) {
        pthread_create(&Far[i], NULL, Farmer, (void *)&ids[i]);
    }
    for (int i = 0; i < 5; i++) {
        pthread_create(&Sho[i], NULL, ShopOwner, (void *)&ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(Far[i], NULL);
        pthread_join(Sho[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

