#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float h(float R, float C, float L, float ome){
    return 1000*ome*C*R/(sqrt(pow((1-1000*1000*ome*ome*C*L), 2) + pow(C*R*ome*1000, 2)));
}

float* linspace(float x1, float x2, int n) {
    float *x = calloc(n, sizeof(float));

    float step = (x2 - x1) / (float)(n - 1);

    for (int i = 0; i < n; i++) {
        x[i] = x1 + ((float)i * step);
    }

    return x;
}

int main(){
    FILE *fp;
    fp = fopen("data.dat", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    float ome_0 = 158, ome_1 = 474;
    float* x = linspace(ome_0, ome_1, 1580);
    float* y = linspace(ome_0, ome_1, 1580);
    for(int i = 0; i<1580;i++){
        y[i] = h(50, 0.00000001, 0.001, x[i]);
        fprintf(fp, "%f\t%f\n", 1000*x[i], y[i]);
    }
    free(x);
    free(y);
    fclose(fp);
    
}

