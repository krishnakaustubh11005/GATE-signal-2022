#include<stdio.h>
#include<math.h>
double calculate_x(int t) {
    double x;
    x = 2 * (cos(M_PI * t / 3) + 2 * cos(2 * M_PI * t / 3) + 3 * cos(M_PI * t)) + 2;
    return x;
}
int main(){
double d[30];
FILE *outputFile = fopen("x_data.txt", "w"); 

    if (outputFile) {
        for (int i = 0; i < 30; i++) {
        	d[i]=calculate_x(i);
            fprintf(outputFile, "%lf \n", d[i]);
        }

        fclose(outputFile);
    } else {
        printf("Error: Failed to open output file\n");
        return 1;
    }
    
    return 0;
}

