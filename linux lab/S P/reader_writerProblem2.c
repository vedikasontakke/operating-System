#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex,writeblock;
int data = 0,rcount = 0;

void *reader(void *arg)
{
  int f;
  f = ((int)arg);
  sem_wait(&mutex);
  rcount = rcount + 1;
  if(rcount==1)
   sem_wait(&writeblock);
  sem_post(&mutex);
  printf("Data read by the reader%d is %d\n",f,data);
  sleep(1);
  sem_wait(&mutex);
  rcount = rcount - 1;
  if(rcount==0)
   sem_post(&writeblock);
  sem_post(&mutex);
}

void *writer(void *arg)
{
  int f;
  f = ((int) arg);
  sem_wait(&writeblock);
  data++;
  printf("Data writen by the writer%d is %d\n",f,data);
  sleep(1);
  sem_post(&writeblock);
}

int main()
{
  int i,b; 
  pthread_t rtid[5],wtid[5];
  sem_init(&mutex,0,1);
  sem_init(&writeblock,0,1);
  for(i=0;i<=2;i++)
  {
    pthread_create(&wtid[i],NULL,writer,(void *)i);
    pthread_create(&rtid[i],NULL,reader,(void *)i);
  }
  for(i=0;i<=2;i++)
  {
    pthread_join(wtid[i],NULL);
    pthread_join(rtid[i],NULL);
  }
  return 0;
}


/*
 A semaphore is a data structure in computer science that is used to control access to shared resources,
  such as shared memory, in a concurrent (multithreaded) system. It's used to ensure that only one thread at 
  a time can access the shared resource, and to coordinate the actions of multiple threads accessing the same resource.
  Semaphores can be used to implement synchronization and mutual exclusion between threads, and are typically
  implemented as an integer value that is protected by a lock. When a thread wants to access the shared resource, 
  it decrements the semaphore's value. If the value is negative, the thread is blocked until the semaphore's value 
  becomes positive. When the thread is finished accessing the resource, it increments the semaphore's value.
 */

/*
A mutex is a lock that is used to protect a shared resource from
 being simultaneously accessed by multiple threads.
*/
