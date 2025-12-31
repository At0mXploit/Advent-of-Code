#include <stdio.h>

int main() {
    FILE *f = fopen("input.txt", "r");

    // Santa and Robo-Santa both start at (0, 0)
    int sx = 0, sy = 0;   // Santa's position
    int rx = 0, ry = 0;   // Robo-Santa's position

    int xs[10000], ys[10000];
    int count = 0;

    // Record the starting house (0, 0)
    xs[count] = 0;
    ys[count] = 0;
    count++;

    int c;
    int step = 0;  // step number: 0, 1, 2, 3, ...

    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') break;

        if (step % 2 == 0) {
            // Santa's turn (even steps: 0, 2, 4, ...)
            if (c == '^') sy++;
            else if (c == 'v') sy--;
            else if (c == '>') sx++;
            else if (c == '<') sx--;
            // Now check Santa's new position
            int seen = 0;
            for (int i = 0; i < count; i++) {
                if (xs[i] == sx && ys[i] == sy) {
                    seen = 1;
                    break;
                }
            }
            if (!seen) {
                xs[count] = sx;
                ys[count] = sy;
                count++;
            }
        } else {
            // Robo-Santa's turn (odd steps: 1, 3, 5, ...)
            if (c == '^') ry++;
            else if (c == 'v') ry--;
            else if (c == '>') rx++;
            else if (c == '<') rx--;
            // Now check Robo-Santa's new position
            int seen = 0;
            for (int i = 0; i < count; i++) {
                if (xs[i] == rx && ys[i] == ry) {
                    seen = 1;
                    break;
                }
            }
            if (!seen) {
                xs[count] = rx;
                ys[count] = ry;
                count++;
            }
        }

        step++;
    }

    fclose(f);
    printf("%d\n", count);
    return 0;
}
