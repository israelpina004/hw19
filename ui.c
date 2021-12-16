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

  int pipe1 = open("pipe1", O_WRONLY);
  int pipe2 = open("pipe2", O_RDONLY);

  char input[100];

  while(1) {
    printf("Enter a string. Type \"exit\" to exit the program: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "exit") == 0) {
      return 0;
    }

    write(pipe1, input, sizeof(input));

    read(pipe2, input, sizeof(input));
    printf("New string: %s\n", input);
  }

  remove("pipe1");
  remove("pipe2");
  close(pipe1);
  close(pipe2);

  return 0;
}
