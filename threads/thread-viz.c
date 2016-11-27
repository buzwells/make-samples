#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRINT 2000

// function to work in a thread
void *print_xs(void *arg) {
  while(1) {
    fputc('x', stderr);
  } 
  pthread_exit(NULL);
}


int main() {
  // declare threads
  pthread_t my_thread[5];       // declare N maximum threads


  // create threads       
  long id;
  for (id = 1; id <= 1; id++) {
    int ret = pthread_create(&my_thread[id], NULL, &print_xs, (void*)id);
  }

  while(1) {
    fputc('o', stderr);
  }

  printf("main program done\n");
  //exit(EXIT_SUCCESS);
  //close main thread
  pthread_exit(NULL);
}

