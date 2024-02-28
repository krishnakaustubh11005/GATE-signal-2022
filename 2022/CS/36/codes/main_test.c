#include<stdio.h>
#include<math.h>
#include "signals_systems.h"
#include<stdlib.h>

int a_n(int n);
int main()
{
    

    FILE *file = fopen("data.txt", "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (int i = 0; i < 20; i++)
    {
        fprintf(file,"%d %d\n", i, a_n(i));
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

