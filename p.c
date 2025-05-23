#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){

pid_t s;
s=fork();
if(s<0)
	printf("Error");
else if(s==0) //child
	{
	printf("I am Child having id %d\n", getpid());
	printf("My parent's id is %d\n", getppid());
	}
else //q>0; parent process
	{
	printf("I am parent having id %d\n", getpid());
	printf("My child'id is %d\n", s);
	}
}
