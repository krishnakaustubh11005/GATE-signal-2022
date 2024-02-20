#include <stdio.h>

// Recursive function to find x_n
double findX(int n, double P, double x) {
    if (n == 0) {
        return x; // Base case: return the current value of x
    } else {
        // Apply the recursive formula x_{n+1} = 0.5 * (x_n + P / x_n)
        return findX(n - 1, P, 0.5 * (x + P / x));
    }
}

int main() {
    double P = 10.0; // Value of P
    int n = 5;       // Value of n for which we want to find x_n

    // Initial guess for x_1
    double x1 = 1.0;

    // Call the recursive function to find x_n
    double xn = findX(n - 1, P, x1); // Start with x_1 = 1, so find x_5 by starting from x_1

    // Print the result
    printf("Value of x_%d for P = %.2f with x1 = %.2f is: %.3f\n", n, P, x1, xn);

    return 0;
}

