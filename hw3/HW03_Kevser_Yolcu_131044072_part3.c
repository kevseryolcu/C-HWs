/*____________________________________________________________________________________*/

/*                  HW03_Kevser_Yolcu_131044072.part3.c                               */
/*              Kevser Yolcu tarafindan 8 Mart 2015'te yazildi                        */
/*                                                                                    */
/*                                  Aciklama                                          */
/*Verilen degerlere gore havadan birakilan bir topun zıplama grafigi				  */
/*   Alinan Degerler:                                                                 */                    
/* 		  Topun                                                                       */
/*            -Atildigi ilk yukseklik                                                 */
/*            -Tepe noktasini olusturacak karakter                                    */
/*            -Grafigi olusturacak karakter                                           */


/*                             Icerik                                                 */
/*____________________________________________________________________________________*/


#include<stdio.h>
/*Grafigi cizen fonksiyon*/
void draw_diag_step(int height, int feet_height, char the_peak_point, char the_road_point);

int main()
{
	
	draw_diag_step(3,3,'k','y');


	return 0;	
}

void draw_diag_step(int height, int feet_height, char the_peak_point, char the_road_point){
	int i,
		j,
		k,
		m;
		
	for(k = height ; k >0 ; --k){/*Topun yuksekliginin azalarak yeni diagramlarin olusmasini 
								 saglayan dongu*/	

		for( i = 0 ; i < k + 1  ; ++i )/*Bir adimdaki tepe noktasina kadar olan yukselmeyi basan dongu*/
		{
			for( j = 0 ; j < ( (i + 1) * feet_height ) ; ++j )
			{
				/* Tepe noktasina kadar olan yukselme icin kullanilan karakter icin */
				if( ( ( i * feet_height ) <= j ) && ( i <  k ) ) 
					printf("%c" , the_peak_point);
				/* Tepe noktasina karakter basmak icin */
				else if( ( i == k ) && ( j == (k * feet_height) )  )
					printf("%c" , the_road_point);
				/* Tepe noktasina kadar olan bosluklar icin*/
				else
					printf(" ");
				
			}
			printf("\nI");
		}
	
		/* Tepe noktasindan sonrasinda olan inisi basan dongu */
		for( i = k  ; i >= 0 ; --i )
		{
			for( j = 0 ; j < ( i * feet_height ) ; ++j )
			{
				if( j < (i * feet_height) - feet_height )
					printf(" ");
				else
					printf("%c" , the_peak_point);
			
			}
			printf("\nI");	
		}
	}

	printf("\nL");
	
	/*Bitis cizgisi icin*/
	for( m = (feet_height * height) ; m > 0 ; --m)
		printf("_ ");
	
	
	printf(">\n");
}

/*____________________________________________________________________________________*/

/*                  HW03_Kevser_Yolcu_131044072.part3.c                               */
/*____________________________________________________________________________________*/

