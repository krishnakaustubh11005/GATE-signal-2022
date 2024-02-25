#include<stdio.h>
#include<math.h>
#include "signals_systems.h"
#include<stdlib.h>

double *linspace(double start, double end, int number_of_values)
{
    double difference = (end-start) / number_of_values;
    double *output = (double *)malloc(number_of_values * sizeof(double));

    for (int i = 0; i < number_of_values; i++)
    {
        *(output+i) = start + i * difference;
    }

    return output;
}

double* sine_for_array(double *array, int length, double omega, double phase, double Amplitude)
{
    double *output = (double *)malloc(length * sizeof(double));

    for (int i = 0; i < length; i++)
    {
        *(output+i) = Amplitude*cos(*(array+i) * omega + phase);
    }

    return output;
}

double* exponential_for_array(double *array, int length)
{
    double *output = (double *)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++)
    {
        *(output+i) = 100*(*(array+i)*exp(-i*M_PI)*(1-M_PI)+exp(-i*M_PI));
    }

    return output;
}

