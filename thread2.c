#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
void* tf(void* arg){
int n=*(int*) arg;
for(int i=0;i<5;i++){
printf("Thread: %d\n", n);
sleep(1);
}
}

int main(){
pthread_t s;
int v=10;
pthread_create(&s, NULL , tf , &v);
pthread_join(s, NULL);
sleep(1);
}
