//program to create a thread . Thread prints o-4 while the main process prints 20-24
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void* thread_f(void* arg);
int main(){
pthread_t s;
pthread_create(&s, NULL, thread_f, NULL);
pthread_join(s, NULL);
printf("Inside the main\n");
for(int i=20;i<=24;i++){
printf("%d\n", i);
sleep(1);
}
return 0;
}
void *thread_f(void *arg){
printf("Inside Thread\n");
for(int j=0;j<=4;j++){
printf("%d\n", j);
sleep(1);
}
return NULL;
}

