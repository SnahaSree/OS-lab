/*race  condition : 2 threads one to increment other decr>*/
#include<stdio.h>
 #include<unistd.h>
 #include<pthread.h>
 #include<semaphore.h>
  int sree=1;
 sem_t se;
 void* f1(){
 int s;
 sem_wait(&se);
 s=sree;
 printf("Thread reads the value %d\n", s);
 s++;
 printf("Update %d\n", s);
 sleep(1); 
sree=s;
 printf("Value of sree is: %d\n", sree);
 sem_post(&se); }
  void* f2(){
 int sr; 
sem_wait(&se);
 sr=sree;
 printf("Thread reads the value %d\n", sr);
sr--;
 printf("Update %d\n", sr);
 sleep(1);
 sree=sr;
 printf("Value of sree is: %d\n", sree); 
sem_post(&se); 
}  
int main(){
  sem_init(&se, 0, 1);
 pthread_t s1, s2;
 pthread_create(&s1, NULL, f1, NULL);
 pthread_create(&s2, NULL, f2, NULL);
 pthread_join(s1, NULL) ; 
pthread_join(s2, NULL);
 printf("Final sree: %d\n", sree); 
}

