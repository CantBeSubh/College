#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define MaxItems 3 
#define WareHouseSize 3 

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int WareHouse[WareHouseSize];
pthread_mutex_t mutex;

void *manufacturer(void *pno){   
  int item;
  for(int i = 0; i < MaxItems; i++){
    item = rand(); //To randomly fill the ware house
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    WareHouse[in] = item;
    printf("Manufacturer %d: Insert Item %d at %d\n", *((int *)pno),WareHouse[in],in);
    in = (in+1)%WareHouseSize;
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
  }
}
void *distributer(void *cno){   
  for(int i = 0; i < MaxItems; i++){
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    int item = WareHouse[out];
    printf("Distributer %d: Remove Item %d from %d\n",*((int *)cno),item, out);
    out = (out+1)%WareHouseSize;
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
  }
}

int main(){ 
  pthread_t man[3],dist[3];
  pthread_mutex_init(&mutex, NULL);
  sem_init(&empty,0,WareHouseSize);
  sem_init(&full,0,0);

  int a[3] = {1,2,3}; 

  for(int i = 0; i < 3; i++) {
    pthread_create(&man[i], NULL, (void *)manufacturer, (void *)&a[i]);
  }
  for(int i = 0; i < 3; i++) {
    pthread_create(&dist[i], NULL, (void *)distributer, (void *)&a[i]);
  }

  for(int i = 0; i < 3; i++) {
    pthread_join(man[i], NULL);
  }
  for(int i = 0; i < 3; i++) {
    pthread_join(dist[i], NULL);
  }

  pthread_mutex_destroy(&mutex);
  sem_destroy(&empty);
  sem_destroy(&full);

  return 0;
}