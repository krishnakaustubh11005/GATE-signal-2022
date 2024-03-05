#include<stdio.h>
#include<math.h>


float generate(int theta_dash, int R, float t){
	float omega = (2*pow(2,0.5)*9.8)/(5*R);
	return (theta_dash/pow(omega,0.5)) * sin(omega*t);
	}


void main(){
	FILE *fptr;
	fptr = fopen("gen_values.txt", "w");
	float t = -0.1; 
	for(int i = 0; i<=100; i++){
		t+=0.1;
		fprintf(fptr, "%f %f %f %f\n" , t, generate(1,1,t), generate(2,2,t), generate(3,3,t));
	}
	fclose(fptr);
}
