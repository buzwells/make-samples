#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// this data shared by threads
int sum;

// threads call this function
void *runner(void *param); 

int main( int argc, char *argv[]) {

  // thread identifier
  pthread_t tid; 
  // set of thread attributes
  pthread_attr_t attr; 

  if (argc != 2) {
    fprintf(stderr, "usage: %s <integer value> \n", argv[0]);
    return -1;
  }

  if(atoi(argv[1]) < 0) {
    fprintf(stderr, "%d must be >= 0 \n", atoi(argv[1]));
    return -1;
  }

  // get the default attributes 
  pthread_attr_init(&attr);
  pthread_create(&tid, &attr, runner, argv[1]);
  pthread_join(tid, NULL);
  printf("sum = %d \n", sum);
}

// The thread will start here
void *runner(void *param) {
  int i, upper = atoi(param);
  sum = 0;

  for( i = 1; i <= upper; i++) {
    sum += i;
  }
  
  pthread_exit(0);
}
