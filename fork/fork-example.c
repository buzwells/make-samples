#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void work(char * name) {
    printf("%s process\n", name);
}

int main() {

    pid_t ret = fork();

    switch(ret) {

    case -1: // error
        printf("Encountered an error forking process.\n");
        exit(1);
    case 0: // child
        work("child");
        sleep(5);
        printf("bye child\n");
        return 0;
    default: // parent
        work("parent");
        sleep(10);
        printf("bye parent\n");
    }

    printf("Closing parent...\n");
    return 0;
}
