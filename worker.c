#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
  int pipe1 = open("pipe1", O_RDONLY);
  int pipe2 = open("pipe2", O_WRONLY);

  char temp[100];

  while(1) {
    read(pipe1, temp, sizeof(temp));
    int i = 0;
    while(temp[i]) {
      if(temp[i] >= 'a' && temp[i] <= 'z') {
        temp[i] = temp[i] - 32;
      }
      i++;
    }
    write(pipe2, temp, sizeof(temp));
  }

  return 0;
}
