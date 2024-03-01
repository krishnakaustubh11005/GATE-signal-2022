#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    // Open the file for writing
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Define variables
    float centerX = 0.0;
    float centerY = 0.0;
    float radius = 2.0;

    // Calculate points on the circumference of the circle and write coordinates to file
    for (int i = 0; i <= 360; i++) {
        float angle = i * PI / 180; // Convert degrees to radians
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        fprintf(file, "%.2f %.2f\n", x, y);
    }

    // Close the file
    fclose(file);
    
    return 0;
}

