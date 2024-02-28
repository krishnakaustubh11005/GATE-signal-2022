// header file for various generally used functions

#ifndef signals_systems
#define signals_systems

//various function declaration

//linspace function in c;
double* linspace(double start, double end, int number_of_values);

//sine function for an array of values;
double* sine_for_array(double *array, int length, double omega, double phase, double Amplitude);

//double exponential for an array of values;
double* exponential_for_array(double *array, int length);

#endif 
