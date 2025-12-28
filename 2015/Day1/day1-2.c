#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    int floor = 0;
    int position = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open input.txt\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        position++;

        if (ch == '(') {
            floor++;
        } else if (ch == ')') {
            floor--;
        }

        if (floor == -1) {
            printf("First time Santa enters the basement at position: %d\n", position);
            break;
        }
    }

    fclose(file);
    return 0;
}

