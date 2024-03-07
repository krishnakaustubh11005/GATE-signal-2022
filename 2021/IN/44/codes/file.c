#include <stdio.h>

void convolve(int input[], int kernel[], int output[], int input_length, int kernel_length, int output_index) {
    if (output_index >= input_length + kernel_length - 1)
        return;
    
    output[output_index] = 0;

    // Calculate the start and end indices for input and kernel
    int start_index = (output_index >= kernel_length - 1) ? output_index - (kernel_length - 1) : 0;
    int end_index = (output_index < input_length - 1) ? output_index : input_length - 1;

    // Convolution
    for (int j = start_index; j <= end_index; j++) {
        output[output_index] += input[j] * kernel[output_index - j];
    }

    // Recursively convolve for the next output index
    convolve(input, kernel, output, input_length, kernel_length, output_index + 1);
}

void convolution(int input[], int kernel[], int output[], int input_length, int kernel_length) {
    convolve(input, kernel, output, input_length, kernel_length, 0);
}

int main() {
    int input[] = {0,0,0,1,1,1,1,1,1,1,1,2,2,2,2,3,3,3,3,1,1,1,1,0,0};
    int kernel[] = {-1, 2, -1};
    int output[7];
    int counter;

    int input_length = sizeof(input) / sizeof(input[0]);
    int kernel_length = sizeof(kernel) / sizeof(kernel[0]);

    convolution(input, kernel, output, input_length, kernel_length);

    // Save output to a text file
    FILE *fp;
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    for (int i = 0; i < input_length + kernel_length - 1; i++) {
        fprintf(fp, "%d\n", output[i]);
    }
    for (int i=0; i<input_length + kernel_length - 1; i++) {
		if(output[i]!=0) {
			counter++;
		}
	}
	
	printf("The number of non-zero output samples is %d\n",counter);
    fclose(fp);

    return 0;
}
