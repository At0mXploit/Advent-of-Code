#include <stdio.h>

int main() {
    FILE *f = fopen("input.txt", "r");

    int x = 0, y = 0;

    int xs[10000], ys[10000];
    int count = 0;

    // Add starting position (0, 0)
    xs[count] = x;
    ys[count] = y;
    count++;

    int c;
    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') break; // Stop at newline

        // Update position
        if (c == '^') y++;
        else if (c == 'v') y--;
        else if (c == '>') x++;
        else if (c == '<') x--;
        else continue; 

        // Check if already visited
        int seen = 0;
        for (int i = 0; i < count; i++) {
            if (xs[i] == x && ys[i] == y) {
                seen = 1;
                break;
            }
        }

        if (!seen) {
            xs[count] = x;
            ys[count] = y;
            count++;
        }
    }

    fclose(f);
    printf("%d\n", count);
    return 0;
}
