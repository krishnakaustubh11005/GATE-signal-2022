#include <stdio.h>
#include<math.h>
// Step function
int u(int x) {
    return x >= 0 ? 1 : 0;
}

// Function to calculate z(n)
int z(int n) {
    int result = 0;
    int k=-100;
    while(k<=2){  // Assuming a range from -100 to 2
        result += pow(2,n+1) * u(k - n + 1);
        k++;
    }
    return result;
}

int main() {
    FILE *fp;
    fp = fopen("data.txt", "w");

    if (fp != NULL) {
    int n = -10;
        while(n <= 10) {
            fprintf(fp, "%d %d\n", n, z(n));
            n++;
        }
        fclose(fp);
        printf("Data written to data.txt successfully.\n");
    } else {
        printf("Error opening file.\n");
    }

    return 0;
}

