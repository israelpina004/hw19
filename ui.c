#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
  mkfifo("pipe1", 0644);
  mkfifo("pipe2", 0644);

  int pipe1 = open("pipe1", O_RDWR);
  int pipe2 = open("pipe2", O_RDWR);

  char input[100];

  while(1) {
    printf("Enter a string. Type \"exit\" to exit the program: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "exit") == 0) {
      return 0;
    }

    write(pipe1, input, sizeof(input));
    close(pipe1);

    read(pipe2, input, sizeof(input));
    printf("New string: %s\n", input);

    close(pipe2);
  }

  return 0;
}
