#include <stdio.h>

// Define the Kronecker delta function
int delta(int n) {
    return (n == 0) ? 1 : 0;
}

// Define the signal h[n]
int h(int n) {
    return delta(n-2) + delta(n-1) + delta(n) + delta(n+1);
}

int main() {
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Generate the signal values for n = -3 to 4
    for (int n = -3; n <= 4; ++n) {
        fprintf(file, "%d\n", h(n));
    }

    fclose(file);
    return 0;
}

