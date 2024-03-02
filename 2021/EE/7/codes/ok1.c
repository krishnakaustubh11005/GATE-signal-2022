#include <stdio.h>

// Define the Kronecker delta function
int delta(int n) {
    return (n == 0) ? 1 : 0;
}

// Define the signal h1[n]
int h1(int n) {
    return delta(n-1) + delta(n+1);
}

int main() {
    FILE *file = fopen("data1.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Generate the signal values for n = -2 to 2
    for (int n = -2; n <= 2; ++n) {
        fprintf(file, "%d\n", h1(n));
    }

    fclose(file);
    return 0;
}

