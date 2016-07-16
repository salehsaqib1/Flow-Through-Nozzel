/*
 * A5_260674863.c
 *
 *  Created on: Apr 2, 2016
 *      Author: Saleh Saqib Fazal
 */

#include <stdio.h>
#include <math.h>

//The text editor is Eclipse and the compiler is MinGW

/*This defines the type of the variable as a pointer to the function that takes
double as an argument and returns a double.*/
typedef double (*DfD)(double, double);

/*This is a function that contains the bisection algorithm which brackets the roots over
an interval and then starts to converge the interval to a point that is the actual root.
It does this by taking midvalues and keeping the interval having a sign change for convergence.*/
double bisection_rf(DfD f, double x0, double x1, double tol, double ratio){
	double middle;

/*finds the middle value of the interval. If the interval is smaller than the tolerance
the for loop breaks by returning the middle value which is the root.
 */
	for (;;) {
		middle = (x0 + x1) / 2.0;
		if (fabs(middle -x0) < tol){
			return middle;
		}

//these statements are used to change interval bounds on sign change
		else if (f(middle, ratio) * f(x0, ratio) < 0.0){
			x1 = middle;
		}
		else{
			x0 = middle;
		}
	}
	return 0.0;
}

//this function returns the mach-area equation for the pointer
double critAFunc(double M, double ratio){
	return (((1/M)* pow((2/2.4)*(1+0.2*M*M), 3)) - ratio);
}

int main(void){
	double ratio;
	double tolerance = 0.001;
	double root_subsonic;
	double root_supersonic;
	DfD f;

	printf("Please enter the ratio A/A*: \n");
	scanf("%lf", &ratio);

/*Since the gradient of the ratio is 0 at ratio=1. Therefore only one value of
M is returned at the point M=1.*/
	if(ratio == 1){
		printf("M = 1");
		return 0;
	}

	f = &critAFunc; //the critical area function is stored in the memory address of the pointer

/*from the charting function, it was noticed that first root is from 0 to 1.
It was also noticed that second root is after 1*/
	root_subsonic = bisection_rf(f, 0, 1, tolerance, ratio);
	root_supersonic = bisection_rf(f, 1, 1000, tolerance, ratio);

	printf("A/A* = %.2lf\n", ratio);	//prints the user input ratio
	printf("M subsonic = %.3lf\n", root_subsonic);	//prints the lower valued root
	printf("M supersonic = %.3lf\n", root_supersonic);	//prints the higher valued root

	return 0;
}
