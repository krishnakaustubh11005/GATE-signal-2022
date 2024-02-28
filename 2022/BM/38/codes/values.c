#include <stdio.h>
#include <math.h>

double generate_y(double t, double a) {
    return (1 - 2 * exp(-a * t));
}

double generate_phase(double w) {
    return -2 * atan(2 * 3.14 * pow(10, w) / 10000.00);
}

// Function to calculate the Laplace transform of u(t)
double laplaceTransform1(double s) {

    // Define the unit step function u(t)
    double u_t = 1.0;  // for t >= 0

    // Perform the integration to calculate the Laplace transform
    double integral_result = 0.0;
    for (double t = 0.0; t < 100; t += 0.001) {
        integral_result += u_t * exp(-s * t) * 0.001;  // Riemann sum approximation
    }

    return integral_result;
}

double laplaceTransform2(double s) {

    // Define the unit step function u(t)
    double u_t = 1.0;  // for t >= 0

    // Perform the integration to calculate the Laplace transform
    double integral_result = 0.0;
    for (double t = 0.0; t < 1; t += 0.00001) {
        integral_result += u_t * exp(-s * t) * exp(-100 * t) * 0.00001;  // Riemann sum approximation
    }

    return integral_result;
}

int main() {
    FILE *file1 = fopen("data6_1.dat", "w");

    if (file1 == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    double a = 0.01;
    for (double t = 0; t <= 200; t += 10) {
        fprintf(file1, "%.4f %.4f\n", t, generate_y(t, a));
    }

    fclose(file1);

    FILE *file2 = fopen("data6_2.dat", "w");

    if (file2 == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    for(double w=0 ; w<=6 ; w+=0.01) {
        fprintf(file2, "%.4f %.4f\n",  w, generate_phase(w));
    }

    fclose(file2);

    FILE *file3 = fopen("data6_3.dat", "w");

    if (file3 == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    for(double s=0 ; s<=6 ; s+=0.01) {
        fprintf(file3, "%.4f %.4f\n",  s, laplaceTransform1(s));
    }

    fclose(file3);

    FILE *file4 = fopen("data6_4.dat", "w");

    if (file4 == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    for(double s=-90 ; s<=100 ; s+=1) {
        fprintf(file4, "%.4f %.4f\n",  s, laplaceTransform2(s));
    }

    fclose(file4);

    return 0;
}

