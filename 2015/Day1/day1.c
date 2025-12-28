#include <stdio.h>

int main() {
  FILE *file;
  char ch;
  int floor = 0;
  int position = 0;

  file = fopen("input.txt", "r");
  
  while ((ch = fgetc(file)) != EOF) {
    position++;
    if (ch == '(') {
      floor++;
    } else if (ch == ')') {
      floor--;
    }
  }

  fclose(file);
  printf("Final Floor: %d\n", floor);
  return 0;
}
