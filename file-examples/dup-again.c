#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {

   int fd1, fd2;
   mode_t filePerms = S_IRUSR | S_IWUSR;
   fd1 = open("file1", O_WRONLY | O_CREAT | O_TRUNC, filePerms);
   fd2 = dup(fd1); 

   write( fd1, "Captain\n", strlen("Captain\n"));
   write( fd2, "Kirk\n", strlen("Kirk\n"));

   close(fd1);
   close(fd2);

}
