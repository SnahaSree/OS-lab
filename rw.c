#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int readCount = 0;
pthread_mutex_t mutex, writeblock;

void* reader(void* arg) {
    pthread_mutex_lock(&mutex);
    readCount++;
    if(readCount == 1)
        pthread_mutex_lock(&writeblock);
    pthread_mutex_unlock(&mutex);

    printf("Reader %d is reading\n", *(int*)arg);

    pthread_mutex_lock(&mutex);
    readCount--;
    if(readCount == 0)
        pthread_mutex_unlock(&writeblock);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* writer(void* arg) {
    pthread_mutex_lock(&writeblock);
    printf("Writer %d is writing\n", *(int*)arg);
    pthread_mutex_unlock(&writeblock);
    return NULL;
}

int main() {
    pthread_t r1, r2, w1;
    int a = 1, b = 2, c = 1;
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&writeblock, NULL);
    pthread_create(&r1, NULL, reader, &a);
    pthread_create(&w1, NULL, writer, &c);
    pthread_create(&r2, NULL, reader, &b);
    pthread_join(r1, NULL);
    pthread_join(w1, NULL);
    pthread_join(r2, NULL);
    return 0;
}
