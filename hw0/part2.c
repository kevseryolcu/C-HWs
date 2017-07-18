/*HW00_Kevser_Yolcu_131044072.c                                       */
/*Written by Kevser Yolcu on February 14, 2015                       */
/*Description                                                        */

/*Takes 2 polynomials of the 2nd degree and outputs multiplication of them                  */
/*inputs:                                                            */
/*  -Coefficients of 2 polynomials of the 2nd degree                 */
/*Outputs:                                                           */
/*  -Multiplication of 2polynomials of 2nd degree polynomial         */

/*                Includes                                           */

#include <stdio.h>
int main()
{
	double ia2, ia1, ia0; /*2. dereceden bir polinomun katsayilari*/
	double ia5, ia4, ia3; /*ilk fonksiyonla carpilacak olan 2. dereceden polinomun katsayilari*/
	double ra4, ra3, ra2, ra1, ra0; /*sonuc polinomunun katsayilari*/
	
	/*ilk polinomun girdilerini alir*/
	printf("Ilk fonksiyonun katsayilarini yaziniz.");
	scanf("%lf%lf%lf", &ia2, &ia1, &ia0);
	
	/*ikinci polinomun girdilerini alir*/
	printf("Ikinci fonksiyonun katsayilarini yaziniz.");
	scanf("%lf%lf%lf", &ia5, &ia4, &ia3);

	/*iki polinomu carpar*/
	ra4=ia2*ia5;
	ra3=(ia2*ia4)+(ia1*ia5);
	ra2=(ia2*ia3)+(ia1*ia4)+(ia0*ia5);
	ra1=(ia1*ia3)+(ia0*ia4);
	ra0=(ia0*ia3);

	/*sonucun ciktisini verir*/
        printf("Iki fonksiyonun carpimi : %5.2fx^4+%5.2fx^3+%5.2fx^2+%5.2fx+%5.2f", ra4, ra3, ra2, ra1, ra0);

return 0;
}

/*       End of HW00_Kevser_Yolcu_131044072.c                         */
