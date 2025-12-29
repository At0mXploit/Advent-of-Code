#include <stdio.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    int l, w, h;
    int total = 0;
    
    while (fscanf(file, "%dx%dx%d", &l, &w, &h) == 3) {
        // Find 2 smallest dimensions for wrapping
        int smallest = l, middle = w, largest = h;
        // Sort the three values
        if (smallest > middle) { int temp = smallest; smallest = middle; middle = temp; }
        if (middle > largest) { int temp = middle; middle = largest; largest = temp; }
        if (smallest > middle) { int temp = smallest; smallest = middle; middle = temp; }
        
        // Ribbon = perimeter of smallest face + volume for bow
        total += 2*smallest + 2*middle + (l * w * h);
    }
    
    fclose(file);
    printf("%d\n", total);
    return 0;
}
