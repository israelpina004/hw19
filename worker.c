#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
  int pipe1 = open("pipe1", O_RDWR);
  int pipe2 = open("pipe2", O_RDWR);

  char temp[100];

  while(1) {
    while(read(pipe1, temp, sizeof(temp))) {
      //Capitalizes input string.
      int i = 0;
      while(temp[i]) {
        if(temp[i] >= 'a' && temp[i] <= 'z') {
          temp[i] = temp[i] - 32;
        }
        i++;
      }
      write(pipe2, temp, sizeof(temp));
    }
  }

  return 0;
}
