#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    FILE *fp;
    fp = fopen("data2.txt", "w");

    // Define parameters
    double Ac = 1.0;  // Carrier amplitude
    double fm = 1.0;  // Frequency of modulating signal
    double fc = 10.0;  // Frequency of carrier signal
    int num_points = 1000;
    double t;
    double m_t, c_t, s_t;

    for (int i = 0; i < num_points; i++) {
        t = (double)i / (double)(num_points - 1) * 2 * PI;

        // Modulating signal
        m_t = 2 * sin(4 * PI * fm * t);

        // Carrier signal
        c_t = Ac * sin(2 * PI * fc * t);

        // Amplitude modulated signal
        s_t = Ac * (1 + m_t) * sin(4 * PI * fc * t);

        // Write data to file
        fprintf(fp, "%.6f %.6f %.6f %.6f\n", t, m_t, c_t, s_t);
    }

    fclose(fp);
    printf("Data written to data.txt\n");

    return 0;
}

