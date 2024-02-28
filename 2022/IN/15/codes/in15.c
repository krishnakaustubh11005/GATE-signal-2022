#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

// Transfer function coefficients H(s) = 6/(s^2 - 5s + 6)
#define A 6
#define B -5
#define C 6

/*
H(s) = A/(s^2 + Bs + C)
s = jw
H(jw) = A/(-w^2 + Bjw + C)
H(jw) = A(-w^2 + C - Bjw)/((-w^2 + C)^2 - B^2w^2) 
*/
void bode_plot(double *freq, double *magnitude, double *phase, int n); // Function to calculate magnitude and phase

int main() 
{
    int n = 100; // Number of frequency points we use for plotting
    double freq[n], magnitude[n], phase[n]; //arrays to store their respective values

    for (int i = 0; i < n; i++)  // Generates logarithmically spaced frequencies from 0.1 to 1000
    {
        freq[i] = pow(10, -1 + (i * 2.0 / (n - 1)));
    }

    bode_plot(freq, magnitude, phase, n);// Gives magnitude and phase at each frequency in the array

    FILE *fp = fopen("values.dat", "w");// Printing the frequency, magnitude, and phase to values.dat
    if (fp == NULL) 
    {
        printf("Error opening file.\n");
        return 1;
    }
    fprintf(fp, "Frequency\tMagnitude\tPhase\n");
    for (int i = 0; i < n; i++) 
    {
        fprintf(fp, "%.6f\t%.6f\t%.6f\n", freq[i], magnitude[i], phase[i]);
    }
    fclose(fp);
    return 0;
}
void bode_plot(double *freq, double *magnitude, double *phase, int n) // Function to calculate magnitude and phase
{
    int i;
    for (i = 0; i < n; i++) 
    {
        double w = freq[i]; //Only frequency considered as we need the frequency response 
        double Hjw_real = A * (-pow(w, 2) + C) / (pow(pow(w, 2) - C, 2) + pow(B * w, 2));   //seperating the real and imaginary parts of H(jw)
        double Hjw_imag = -A * B * w / (pow(pow(w, 2) - C, 2) + pow(B * w, 2));
        magnitude[i] = 20 * log10(sqrt(pow(Hjw_real, 2) + pow(Hjw_imag, 2)));  //Magnitude plot is in dB
        phase[i] = atan2(Hjw_imag, Hjw_real) * 180 / PI;                       //Converting radians to degrees for phase plot 
    }
}
