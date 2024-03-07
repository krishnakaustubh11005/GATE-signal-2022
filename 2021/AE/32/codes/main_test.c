#include<stdio.h>
#include<math.h>
#include "signals_systems.h"
#include<stdlib.h>

//Code for solving matrix eqautions involving 2*2 matrices
int main()
{
    double* time;
    double* x_1B;
    double* x_2B;
    double* x_1C;
    double* x_2C;
    double omega_1= 233.9;
    double omega_2= 324.5;
    int length = 200;
//time will be found by using linspace function 
 
    time = linspace(0.0,5.0,length);
    x_1B=cosine_for_array(time,length,omega_1,0,2.0);
    x_2B=cosine_for_array(time,length,omega_1,0,-6.32);
    x_1C=sum_of_two_cosines(time,length,omega_1,0,1.316,omega_2,0,0.683);
    x_2C=sum_of_two_cosines(time,length,omega_1,0,-4.158,omega_2,0,2.158);

    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (int i = 0; i < length; i++)
    {
        fprintf(file,"%lf %lf %lf %lf %lf\n", *(time+i), *(x_1B+i),*(x_2B+i), *(x_1C+i),*(x_2C+i));
    }
    
    fclose(file);
    return 0;
}

int a_n(int n)
{
    if(n%2==0)
    {
        return unit_step(n);
    }
    else
    {
        return (n+1)*unit_step(n);
    }
}

