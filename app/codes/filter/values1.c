#include <stdio.h>
#include<math.h>
#include <float.h>
#define PI 3.14

double y_t1(double t) {
    double p1 = -50;
    double p2 = -100;
    return 1 + p2 * exp(p1 * t)/ (p1 - p2) + p1 * exp(p2 * t)/ (p2 - p1) * (t >= 0) ;
}

double y_t2(double t) {
    double p = -75;
    return (1 + (p * t - 1) * exp(p * t)) * (t >= 0) ;
}

double y_t3(double t) {
    double w_d = 1950;
    double sigma = 50;
    double p = 2000;
    double phi = PI - atan(sigma / w_d);
    return 1 + (p / w_d) * exp(-sigma * t) * cos(w_d * t + phi) * (t >= 0) ;
}

int main() {
    FILE *fp;
    fp = fopen("data.dat", "w");

    for (double t = 0; t <= 0.25; t += 0.001) {
        fprintf(fp, "%e %e %e %e\n", t, y_t1(t), y_t2(t), y_t3(t));
    }

    fclose(fp);

    return 0;
}

