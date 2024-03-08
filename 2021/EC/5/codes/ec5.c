#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

//We define the data type for a complex number 
typedef struct 
{ 
    float real;
    float imag;
} complex ;

complex* dft(float* signal, int signal_length) //The entire signal is passes along with the signal length to compute dft of all terms
{
    complex* transform = (complex*)malloc(signal_length * sizeof(complex));
    for (int k = 0; k < signal_length; k++)
    { 
        transform[k].real = 0; //Initialsing the term of the idft
        transform[k].imag = 0;
        for (int n = 0; n < signal_length; n++) //X[k]
        {
            float angle = 2 * PI * k * n / signal_length;  //exponential power for the dft formula
            transform[k].real += signal[n] * cos(angle);  //Summation of real and imaginary parts seperately by e^ix = cos(x) + isin(x)
            transform[k].imag -= signal[n] * sin(angle); //-ve for sine term
        }
    }
    return transform;
}

float* idft(complex* transform, int signal_length)
{
    float* signal = (float*)malloc(signal_length * sizeof(float));
    for (int n = 0; n < signal_length; n++) {
        signal[n] = 0;
        for (int k = 0; k < signal_length; k++) {
            float angle = 2 * PI * k * n / signal_length;
            signal[n] += (transform[k].real * cos(angle) + transform[k].imag * sin(angle)) / signal_length;  //again considering -ve term of the sine
        }
    }
    return signal;
}

int main()
 {
    // We have taken two set of values for x[n] and h[n] and we will demostrate the solution with this example
    float x[16];
    float h[16];
    for (int i = 0; i < 16; i++) //Inputs x and h
    {
        x[i] = i + 1; // x[n] = {1, 2, 3, ..., 16}
        h[i] = 1;     // h[n] = {1, 1, 1, ..., 1}
    }

    //y[n] is the linear convolution of x[n] and h[n]
    float y[31];
    for (int n = 0; n < 31; n++)
    {
        y[n] = 0;
        for (int k = 0; k < 16; k++) {
            if (n - k >= 0 && n - k < 16)
                y[n] += x[n - k] * h[k];
        }
    }

    // Computing the DFT of x[n] and h[n]
    complex* X = dft(x, 16);
    complex* H = dft(h, 16);

    // Computing the product of DFTs
    complex* product = (complex*)malloc(16 * sizeof(complex));      // The term for X[f]H[f]
    for (int i = 0; i < 16; i++)
    {
        product[i].real = X[i].real * H[i].real - X[i].imag * H[i].imag;
        product[i].imag = X[i].real * H[i].imag + X[i].imag * H[i].real;
    }

    // Compute IDFT of the product
    float* z = idft(product, 16);

    // Output y[n] and z[n] values to file
    FILE* fp = fopen("values.dat", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // printing the y[n] values in values.dat file
    for (int i = 0; i < 31; i++) {
        fprintf(fp, "%f ", y[i]);
    }
    fprintf(fp, "\n"); // Newline after y[n]

    // printing the z[n] values in values.dat file
    for (int i = 0; i < 16; i++) {
        fprintf(fp, "%f ", z[i]);
    }
    fprintf(fp, "\n"); 

    fclose(fp);

    // Freeing the used memory
    free(X);
    free(H);
    free(product);
    free(z);

    return 0;
}
