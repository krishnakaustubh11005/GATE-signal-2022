#include <stdio.h>
#include <math.h>

#define NUM_POINTS 1000
#define TIME_MAX 0.006
#define CARRIER_FREQUENCY 1000000
#define MESSAGE_FREQUENCY 1000
#define CARRIER_AMPLITUDE 2
#define MESSAGE_AMPLITUDE (4 * sqrt(2))

int main() {
    FILE *carrier_file = fopen("data1.txt", "w");
    FILE *message_file = fopen("data2.txt", "w");

    if (carrier_file == NULL || message_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    double t, carrier_signal, message_signal;
    for (int i = 0; i < NUM_POINTS; ++i) {
        t = i * TIME_MAX / NUM_POINTS;

        // Calculate carrier signal
        carrier_signal = CARRIER_AMPLITUDE * cos(2 * M_PI * CARRIER_FREQUENCY * t);
        fprintf(carrier_file, "%lf %lf\n", t, carrier_signal);

        // Calculate message signal
        message_signal = MESSAGE_AMPLITUDE * sin(2 * M_PI * MESSAGE_FREQUENCY * t);
        fprintf(message_file, "%lf %lf\n", t, message_signal);
    }

    fclose(carrier_file);
    fclose(message_file);

    printf("Data saved successfully.\n");
    return 0;
}

