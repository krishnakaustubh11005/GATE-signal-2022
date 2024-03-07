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

double* cosine_for_array(double *array, int length, double omega, double phase, double Amplitude)
{
    double *output = (double *)malloc(length * sizeof(double));

    for (int i = 0; i < length; i++)
    {
        *(output+i) = Amplitude*cos(*(array+i) * omega + phase);
    }

    return output;
}

double* sum_of_two_cosines(double *array, int length, double omega_1, double phase_1, double Amplitude_1,double omega_2, double phase_2, double Amplitude_2)
{
    double *output = (double *)malloc(length * sizeof(double));

    for (int i = 0; i < length; i++)
    {
        *(output+i) = Amplitude_1*cos(*(array+i) * omega_1 + phase_1)+ Amplitude_2*cos(*(array+i) * omega_2 + phase_2);
    }

    return output;
}
int unit_step(int n)
{
    if(n>=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

