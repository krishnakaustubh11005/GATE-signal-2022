#include <stdio.h>

// Define the Kronecker delta function
int delta(int n) {
    return (n == 0) ? 1 : 0;
}

// Define the signal h2[n]
int h2(int n) {
    return delta(n) + delta(n-1);
}

int main() {
    FILE *file = fopen("data2.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Generate the signal values for n = -1 to 2
    for (int n = -1; n <= 2; ++n) {
        fprintf(file, "%d\n", h2(n));
    }

    fclose(file);
    return 0;
}

