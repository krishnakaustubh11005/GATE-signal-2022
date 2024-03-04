#include <stdio.h>
#include <math.h>

#define N 61  // Number of samples, i from -30 to 30
#define PI 3.14159265358979323846

int main() {
    FILE *fp;
    fp = fopen("values.dat", "w");

    double f[N], X[N], X_2f[N], convolution[N];
    double delta_f = 30.0 / N;

    // Define frequency range for X(f) - triangular pulse
    for (int i = -30; i <= 30; i++) {
        int idx = i + 30;
        f[idx] = i;
        X[idx] = 0.0;
        if (f[idx] >= -10 && f[idx] <= 0)
            X[idx] = 1 + f[idx] / 10;
        else if (f[idx] > 0 && f[idx] <= 10)
            X[idx] = 1 - f[idx] / 10;
    }

    // Define frequency range for X(2f) - triangular pulse
    for (int i = -30; i <= 30; i++) {
        int idx = i + 30;
        X_2f[idx] = 0.0;
        if (f[idx] >= -5 && f[idx] <= 0)
            X_2f[idx] = 1 + f[idx] / 5;
        else if (f[idx] > 0 && f[idx] <= 5)
            X_2f[idx] = 1 - f[idx] / 5;
    }

    // Compute convolution of X(f) and X(2f)
    for (int i = -30; i <= 30; i++) {
        convolution[i + 30] = 0.0;
        for (int j = -30; j <= 30; j++) {
            double tau = f[j + 30] / 2.0;
            if (i - j >= -30 && i - j <= 30)  // Check limits for convolution
                convolution[i + 30] += X[j + 30] * X_2f[i - j + 30] * delta_f;
        }
    }

    // Save values in the file
    for (int i = 0; i < N; i++) {
        fprintf(fp, "%lf %lf %lf %lf\n", f[i], X[i], X_2f[i], convolution[i]);
    }

    fclose(fp);

    return 0;
}

