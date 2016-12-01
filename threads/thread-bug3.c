#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#define NUM_THREADS 5

long a = 0;
long b = 0;
pthread_mutex_t a_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t b_mutex = PTHREAD_MUTEX_INITIALIZER;

// increments a and adds it to b 
void *a_thread(void *arg) {
  printf("This thread increments a and adds to b\n");
  int ret = pthread_mutex_lock(&a_mutex);
  if(ret == EINVAL) {
    printf("Error locking a_mutex\n");
    pthread_exit(NULL);
  }
  sleep(1);
  a++;
  ret = pthread_mutex_lock(&b_mutex);
  if(ret == EINVAL) {
    printf("Error locking b_mutex\n");
    pthread_exit(NULL);
  }
  sleep(1);
  b += a;
  pthread_mutex_unlock(&b_mutex); 
  pthread_mutex_unlock(&a_mutex);
  pthread_exit(NULL);
}

// increments b and multiplies a by it 
void *b_thread(void *arg) {
  printf("This thread increments b and multiplies a by b\n");
  int ret = pthread_mutex_lock(&b_mutex);
  if(ret == EINVAL) {
    printf("Error locking b_mutex\n");
    pthread_exit(NULL);
  }
  b++;
  ret = pthread_mutex_lock(&a_mutex);
  if(ret == EINVAL) {
    printf("Error locking a_mutex\n");
    pthread_exit(NULL);
  }
  a *= b;
  pthread_mutex_unlock(&a_mutex); 
  pthread_mutex_unlock(&b_mutex);
  pthread_exit(NULL);
}

int main() {
  // declare threads
  pthread_t my_a_thread[5];       // declare N maximum threads
  pthread_t my_b_thread[5];

  // create threads       
  long id;
  for (id = 0; id < 5; id++) {
    int ret = pthread_create(&my_a_thread[id], NULL, &a_thread, NULL);
    ret = pthread_create(&my_b_thread[id], NULL, &b_thread, NULL);
  }

  for (id = 0; id < 5; id++) {
    pthread_join(my_a_thread[id], NULL);
    pthread_join(my_b_thread[id], NULL);
  }

  printf("main program done\n");
  printf("a = %ld\n", a);
  printf("b = %ld\n", b);
  //close main thread
  pthread_exit(NULL);
}

