
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
/*
wsem: controls the access to the shared resource by the writers.
rsem: controls the access to the shared resource by the readers.
x: provides mutual exclusion between multiple readers accessing the shared resource simultaneously.
y: provides mutual exclusion between multiple writers accessing the shared resource simultaneously.
*/
void * reader(void *) ;  
void *writer (void *) ;  
// data-type which is used to delcare semaphore variables
// semaphore variables are wsem , rsem 
sem_t x,y,z,wsem,rsem ;  
int readcount=0 ;  
int writecount=0 ;  

main()  
{  
  int a=1,b=1;  
  system("clear");  

  /*
  sem_init : The sem_init function is used to initialize a semaphore.
  1st parameter : pointer to semaphore pobject
  2nd parameter : pshared zero-- semaphore is not shared 
                        non-zero -- semaphore is shared between processes
  3rd parameter : value: Initial value of the semaphore.                       
  */
  sem_init(&wsem,0,1) ;  
  sem_init(&x,0,1) ;  
  sem_init(&rsem,0,1) ;  
  sem_init(&y,0,1) ;  
  sem_init(&z,0,1) ;  

//pthread_t variables are used to represent individual threads
  pthread_t r,w,r1,w1,r2,r3,w2,w3 ;  

  // creating threads
  pthread_create(&r,NULL,reader,(void *)a);  
     a++;  
  pthread_create(&r1,NULL,reader,(void *)a);  
     a++;  
  pthread_create(&w,NULL,writer,(void *)b);  
     b++;  
   pthread_create(&w1,NULL,writer,(void *)b);  
     b++;  
  pthread_create(&r2,NULL,reader,(void *)a);  
     a++;  
  pthread_create(&w2,NULL,writer,(void *)b);  
     b++;  
  pthread_create(&r3,NULL,reader,(void *)a);  
     a++;  
  pthread_create(&w3,NULL,writer,(void *)b);  

  //The pthread_join function blocks the calling thread until the specified thread 
  //(specified by the pthread_t argument) terminates.
  pthread_join(r,NULL);  
  pthread_join(r1,NULL);  
  pthread_join(w,NULL);  
  pthread_join(w1,NULL);  
  pthread_join(r2,NULL);  
  pthread_join(w2,NULL) ;  
  pthread_join(r3,NULL);  
  pthread_join(w3,NULL);  
  printf("main terminated\n");  
 }  
void * reader(void * arg)  
{  
   int c=(int)arg ;  
   printf("\nreader %d is created",c);  
   sleep(1);  

/*
The sem_wait function is used to decrement the value of a semaphore.
If the resulting value is negative, the calling thread will be blocked until the 
semaphore value becomes positive again. 
*/

   sem_wait(&rsem);  
   sem_wait(&x) ;  
   readcount++;  
   if(readcount==1)  
         sem_wait(&wsem) ;  

/*
The sem_post function increments the value of a semaphore. It is typically used to signal to 
another thread that a resource has become available, or that a task has been completed. When a
semaphore's value is incremented, any threads waiting on the semaphore are unblocked and able to 
continue execution.
*/

   sem_post(&x) ;  
   sem_post(&rsem);  
   sleep(1)  ;

 /*Critcal Section */  

  printf("\n\nreader %d is reading\n ",c);  
  sleep(1) ;  
  printf("\nreader%d finished reading\n",c); 

 /* critical section completd */  
  sem_wait(&x) ;  
  readcount-- ;  
  if(readcount==0)  
     sem_post(&wsem) ;  
  sem_post(&x) ;  
 } 

void * writer(void * arg)  
{  
  int c=(int)arg ;  
  printf("\nwriter %d is created",c);  
  sleep(1);  
  sem_wait(&y) ;  
  writecount++ ;  
  if(writecount==0)  
      sem_wait(&rsem) ;  
  sem_post(&y) ;  
  sem_wait(&wsem) ;  
  printf("\nwriter %d is writing\n",c) ;  
  sleep(1);  
  printf("\nwriter%d finished writing\n",c);  
  sem_post(&wsem) ;  
  sem_wait(&y) ;  
  writecount-- ;  
  if(writecount==0)  
      sem_post(&rsem) ;  
  sem_post(&y) ;  
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

