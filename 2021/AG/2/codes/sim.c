#include <stdio.h>
 double x=1;
 double result=0;
 
 double func(double x) {
   
   if(x<10000000000000000){
       
       result=(x*(x+1))/(2*x*x);
       printf("For x=%.0f,the value is %.15f\n",x,result);
      func(10*x);
   }
     
 }
 
void main() {
    
func(x);

}

