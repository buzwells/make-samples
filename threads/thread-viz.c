#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRINT 2000
#define NUM_THREADS 5
// array of characters for each thread
char display[5] = "abcde";

// function to work in a thread
void *print_xs(void *arg) {
  long x = (long) arg;

  while(1) {
    fputc(display[x], stderr);
  } 
  pthread_exit(NULL);
}


int main() {
  // declare threads
  pthread_t my_thread[5];       // declare N maximum threads

  // create threads       
  long id;
  for (id = 0; id < NUM_THREADS; id++) {
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

