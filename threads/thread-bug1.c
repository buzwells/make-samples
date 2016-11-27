#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int sum = 0;
pthread_mutex_t common_mutex;

// function to work in a thread
void *worker_thread(void *arg) {
  printf("This is worker_thread #%ld\n", (long)arg);
  for(int a = 0; a < 5; a++) {
    int ret = pthread_mutex_lock(&common_mutex);
    if(ret == EINVAL) {
      printf("Encountered an error trying to lock mutex\n");
    }
    if( sum < 15 ) {
      sleep(1);
      sum++;
    } else {
      printf("Cap is reached in work thread #%ld\n", (long) arg);
      break;
    }
    pthread_mutex_unlock(&common_mutex);
  }
  pthread_exit(NULL);
}


int main() {
  // declare threads
  pthread_t my_thread[5];       // declare N maximum threads


  // create threads       
  long id;
  for (id = 1; id <= 5; id++) {
    int ret = pthread_create(&my_thread[id], NULL, &worker_thread, (void*)id);
  }

  for (id = 1; id <= 5; id++) {
    pthread_join(my_thread[id], NULL);
    printf("thread %ld is done\n", id);
  }

  printf("main program done - sum = %d\n", sum);
  //exit(EXIT_SUCCESS);
  //close main thread
  pthread_exit(NULL);
}

