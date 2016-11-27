#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// function to work in a thread
void *worker_thread(void *arg) {
  printf("This is worker_thread #%ld\n", (long)arg);
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


  printf("main program done\n");
  //exit(EXIT_SUCCESS);
  //close main thread
  pthread_exit(NULL);
}

