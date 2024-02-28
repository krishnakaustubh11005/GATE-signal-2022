#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double calculate_impedance(double resistance, double inductance, double capacitance, double frequency) {
    double XL = 2 * PI * frequency * inductance; 
    double XC = 1 / (2 * PI * frequency * capacitance);

    return sqrt(pow(resistance, 2) + pow((XL - XC), 2));
}

int main() {
    double voltage = 220;  
    double frequency = 50; 
    double resistance = 550; 
    double capacitance = 0.000003858;

    FILE *fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (int i = 0; i <= 1000; i++) {
        double inductance = 10.0 * i / 1000.0; 

        double impedance = calculate_impedance(resistance, inductance, capacitance, frequency);

        double current = voltage / impedance;

        fprintf(fp, "%.6lf %.6lf\n", inductance, current);
    }

    fclose(fp);


    return 0;
}

