#include <stdio.h>
#include <math.h>
#include <float.h>

double zero1(double w) {
    if(log10(w) > 1.0) {
        return 20.0 * (log10(w) - 1.0);
    }else{
        return 0.0;
    }
}

double pole1(double w) {
    if(log10(w) > 0) {
        return -20.0 * log10(w);
    }else{
        return 0.0;
    }
}

double pole2(double w) {
    if(log10(w) > 0.1) {
        return -20.0 * (log10(w) - 0.1);
    }else{
        return 0.0;
    }
}

double pole3(double w) {
    if(log10(w) > -log10(0.5)) {
        return -20.0 * (log10(w) + log10(0.5));
    }else{
        return 0.0;
    }
}

double pole4(double w) {
    if(log10(w) > 2.0) {
        return -20.0 * (log10(w) - 2.0);
    }else{
        return 0.0;
    }
}

int main() {
    FILE *fp;
    fp = fopen("data7.dat", "w");
    
    for (double w = 0.01; w <= 1000.0; w += 0.01) {
        fprintf(fp, "%f %f %f %f %f %f %f %f\n", log10(w), zero1(w), pole1(w), pole2(w), pole3(w), pole4(w), -20.0, zero1(w)+pole1(w)+pole2(w)+pole3(w)+pole4(w)-20.0);
    }

    fclose(fp);

    return 0;
}

