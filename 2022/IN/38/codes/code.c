#include <stdio.h>
#include <math.h>

#define N_VALUES 30 // Number of values of n

// Define the function H_d(n)
double H_d(int n) {
    return (1.0 / 323) * (n == 0 ? 1 : 0) + (340.0 / 6783) * pow(19.0 / 21, n) - (380.0 / 7429) * pow(17.0 / 23, n);
}

int main() {
    FILE *file;
    file = fopen("data.out", "w");
    
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Compute and save values of H_d(n)
    for (int n = 0; n < N_VALUES; n++) {
        double value = H_d(n);
        fprintf(file, "%d %.10f\n", n, value);
    }
    
    fclose(file);
    return 0;
}

