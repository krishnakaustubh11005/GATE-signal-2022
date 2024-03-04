#include <stdio.h>
#include <math.h>

int main() {
    // Given parameters
    float V_rms=200;
    float f= 50;
    float R_load=50 ;

    // Calculate other parameters
    float V_m = sqrt(2) * V_rms;
    float V_load = V_m / 2;
    float V_dc = V_load / M_PI;
    float I_dc = V_dc / R_load;
    float P = I_dc * I_dc * R_load;

    // Save coordinates to coordinate.txt
    FILE *file = fopen("coordinate.txt", "w");
    if (file != NULL) {
        fprintf(file, "%.2f %.2f %.2f", V_rms, f, P);
        fclose(file);
    } else {
        printf("Error opening file for writing.\n");
        return 1;
    }

    return 0;
}

