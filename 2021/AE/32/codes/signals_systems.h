// header file for various generally used functions

#ifndef signals_systems
#define signals_systems

//various function declaration

//linspace function in c;
double* linspace(double start, double end, int number_of_values);

//unit step function in c;
int unit_step(int n);

//sine function for an array of values;
double* cosine_for_array(double *array, int length, double omega, double phase, double Amplitude);

//superposition of two waves;
double* sum_of_two_cosines(double *array, int length, double omega_1, double phase_1, double Amplitude_1,double omega_2, double phase_2, double Amplitude_2);



#endif 
