#include<stdio.h>
#include<sys/shm.h>  
#include<stdlib.h>
#include<unistd.h>
int main()
{ 
 int shmid;
 void *shm;
 char str[100];
 shmid=shmget((key_t)2366,1024,0666);
 printf("the  key of the shared memory is %d \n",shmid);
 shm=shmat(shmid,NULL,0);
 printf("process is attached at %p\n",shm);
 printf("the value read from shared is %s\n",(char*)shm);
 return 0;
}
