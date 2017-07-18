/*HW00_Kevser_Yolcu_131044072.c                                                        */
/*Written by Kevser Yolcu on February 14, 2015                                          */
/*Description                                                                           */

/*Takes the integral of given 1st degree polynomial                                     */
/*inputs:                                                                               */
/*  -coefficients of the 1st degree polynomial                                          */
/*  -Zero input value of resulting polynomial                                           */
/*Outputs:                                                                              */
/*  -Resulting 2nd degree polynomial                                                    */

/*                Includes                                                              */

#include <stdio.h>
int main()
{
	double ia1,ia2;  /*coefficients of the input poly*/
	double k=0.5;  /*coefficient of the integral of x*/
	double p0;  /*P(0) value of the resulting poly*/
	double ra2, ra1, ra0; /*coefficients of the resulting poly*/

	/*get the 1st degree input polynomial*/
	printf("Enter the coefficients of the polynomial (from higher to lower order)-");
	scanf("%lf%lf" , &ia1, &ia2);

	/*get the zero input value of resulting poly*/
	printf("Enter p(0) value for the resulting polynomial-");
	scanf ("%lf", &p0);
	
	/*calculate the resulting poly*/
	ra2=ia1*k;
	ra1=ia1;
	ra0=p0;
	
	/*output the resulting poly*/
	printf("The result polynomial is: %5.2fx^2, %5.2fx, %5.2f", ra2, ra1, ra0);

return 0;	
}

/*       End of HW00_Kevser_Yolcu_131044072.c                                              */
