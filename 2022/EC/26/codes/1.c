#include <stdio.h>
#include <math.h>

int main() {
    FILE *file = fopen("1.dat", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    #define n 300000
    #define step 0.01 

    double x, y;

    for (int i = 0; i < n; i++) {
        x = i * step;
        y = 20*log10(2*x/ sqrt(x*x + 1000000));
        fprintf(file, "%lf\t%lf\n", x, y);
    }        
fclose(file);
return 0;
}
