#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#define NUM_THREADS 5

int sum = 0;
pthread_mutex_t common_mutex;
long tasks[NUM_THREADS];

// function to work in a thread
void *worker_thread(void *arg) {
  printf("This is worker_thread #%ld\n", (long)arg);
  for(int a = 0; a < 5; a++) {
    if( sum < 15 ) {
      sleep(1);
      printf("incrementing sum\n");
      int ret = pthread_mutex_lock(&common_mutex);
      if(ret == EINVAL) {
        printf("Encountered an error trying to lock mutex\n");
        pthread_exit(NULL);
      }
      sum++;
      pthread_mutex_unlock(&common_mutex);
    } else {
      printf("Cap is reached in work thread #%ld\n", (long) arg);
    }
  }
  pthread_exit(NULL);
}


int main() {
  // declare threads
  pthread_t my_thread[5];       // declare N maximum threads


  // create threads       
  long id;
  for (id = 0; id < 5; id++) {
    tasks[id] = id;
    int ret = pthread_create(&my_thread[id], NULL, &worker_thread, (void*) tasks[id]);
  }

  for (id = 0; id < 5; id++) {
    pthread_join(my_thread[id], NULL);
    printf("thread %ld is done\n", id);
  }

  printf("main program done - sum = %d\n", sum);
  //close main thread
  pthread_exit(NULL);
}

