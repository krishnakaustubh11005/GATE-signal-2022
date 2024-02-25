#include <stdio.h>
#include <math.h>

#define NUM_POINTS 101 // Number of points for omega from 0 to 10 by incrementing omega by 0.1

double magnitude_response(double omega) {
    return 3 / sqrt(1 + omega * omega);
}

double phase_response(double omega) {
    double numerator = omega * cos(3 * omega) + sin(3 * omega);
    double denominator = omega * sin(3 * omega) - cos(3 * omega);
    double phase = atan2(numerator, denominator) * 180 / M_PI;
    
    // Ensure phase is within the range -180 to 180 degrees
    if (phase > 180)
        phase -= 360;
    else if (phase < -180)
        phase += 360;
    
    return phase;
}

int main() {
    FILE *freqFile = fopen("freq.dat", "w");
    if (freqFile) {
        double w[NUM_POINTS], magnitude[NUM_POINTS], phase[NUM_POINTS];

        // Calculate values for magnitude and phase responses
        for (int i = 0; i < NUM_POINTS; ++i) {
            w[i] = i * 0.1; // Increment omega by 0.1 starting from 0
            magnitude[i] = magnitude_response(w[i]);
            phase[i] = phase_response(w[i]);
            // Write frequency, magnitude, and phase to file
            fprintf(freqFile, "%lf %lf %lf\n", w[i], magnitude[i], phase[i]);
        }

        fclose(freqFile);
    } else {
        printf("Error: Unable to create file.\n");
    }
    
    return 0;
}

