//create a thread to add two numbers
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>

void* tf(void* arg){
printf("Inside Thread\n");
int *s=arg;
int sum= s[0]+s[1]-s[2]+s[3];
printf("Sum: %d\n", sum);
//pthread_exit("Sum calculated");
}
int n[4]={1,2,3,4};

int main(){
//void* r;
pthread_t sr;
pthread_create(&sr, NULL, tf, (void*)n);
pthread_join(sr,NULL);
printf("Inside main process\n");
//printf("Thread returned:%s\n", (char*)r);
}

