#include <stdio.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    int l, w, h;
    int total = 0;
    
    while (fscanf(file, "%dx%dx%d", &l, &w, &h) == 3) {
        int a = l * w;
        int b = w * h;
        int c = h * l;
        
        int smallest = a;
        if (b < smallest) smallest = b;
        if (c < smallest) smallest = c;
        
        total += 2*a + 2*b + 2*c + smallest;
    }
    
    fclose(file);
    printf("%d\n", total);
    return 0;
}
