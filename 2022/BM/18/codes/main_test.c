#include<stdio.h>
#include<math.h>
#include "signals_systems.h"
#include<stdlib.h>


int main()
{
    double start = 0;
    double end = 10;
    int number_of_values = 1000;
    double omega = 6;
    double phase1 = M_PI/3;
    double phase2 = M_PI/2;
    double Amplitude_1 = 2;
    double Amplitude_2 =3;
    double *t_values = linspace(start, end, number_of_values);
    double *v_1_t = sine_for_array(t_values, number_of_values, omega, phase1, Amplitude_1);
    double *v_2_t = sine_for_array(t_values, number_of_values, omega, phase2,  Amplitude_2);

    FILE *file = fopen("data.txt", "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (int i = 0; i < number_of_values; i++)
    {
        fprintf(file,"%lf %lf %lf\n", *(t_values + i), *(v_1_t + i), *(v_2_t+i));
    }
    
    fclose(file);
    return 0;
}

