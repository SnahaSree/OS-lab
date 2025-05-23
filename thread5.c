#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
void* max(void* arg){
int* n=(int*) arg;
int m=n[0];
for(int i=0;i<3;i++){
if(n[i]>m)
m=n[i];
}
printf("Max: %d\n", m);
}
int main(){
pthread_t s;
int t[3]={3829, 3383, 5985};
pthread_create(&s, NULL, max, t);
pthread_join(s, NULL);
}
