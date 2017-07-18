/*____________________________________________________________________________________*/

/*                  HW03_Kevser_Yolcu_131044072_part1.c                               */
/*              Kevser Yolcu tarafindan 4 Mart 2015'te yazildi                        */
/*                                                                                    */
/*                                  Aciklama                                          */
/*0-10 arasinda rastgele tutulan bir sayinin tahmin edilmesi                          */
/*   Alinan Degerler:                                                                 */                    
/* 		-Rastgele tutulan sayi                                                        */
/*      -Tahmin                                                                       */

/*   Cikan Degerler:                                                                  */
/*            -Kullanicinin tahminine gore uyarilar                                   */

/*                             Icerik                                                 */
/*____________________________________________________________________________________*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Fonksiyonlarin tanitilmasi*/

int RNG();/*0-10 arasinda rastgele bir sayi tutan fonksiyon*/
void warn_the_player(int uzaklik);	/*Kullanicinin cevabina gore uyari veren fonksiyon*/
int calculate_the_difference(int sayi2, int thmn);/*Tutulan sayi ile tahmin
												 arasindaki farki bulan fonksiyon*/

int main(){
	/*Degiskenlerin tanitilmasi*/
	int tahmin,
		tutulan_sayi,
		yakinlik;
	char secim;
		
		/*Oyunun oynanip oynanmama seceneginin sunulmasi*/
		printf("If you wanna play please press P, if you don't please press E >\n ");
		scanf("%c", &secim);

		if(secim == 'P' || secim == 'p'){

			/*fonksiyonun cagirilmasi*/
			tutulan_sayi = RNG();        

			/*Kullanicidan tahmin istenmesi*/
			printf("Come on guess the number: ");
			scanf("%d",&tahmin);
		
			/*Fonksiyon ile farkin bulunmasi*/
			yakinlik = calculate_the_difference(tutulan_sayi,tahmin);   

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     	   		/*Tutulan sayi ile tahminin farkinin sifira esit olmamasi durumunda
			  oyuncudan yeni tahmin istenmesi                                  */
			while(yakinlik != 0){

				warn_the_player(yakinlik);
		
				printf("Please guess the number again: ");
				scanf("%d",&tahmin);

				yakinlik = calculate_the_difference(tutulan_sayi,tahmin);			
			}

			/*Farkin karsilastirilmasi*/
			if(yakinlik==0)
				printf("You win, congratulations\a\n");

		}

		else if(secim == 'E' || secim == 'e'){
			printf("Goodbye...\n");
			return 0;
		}
		
		else
			printf("You pressed wrong character.\n");

	return 0;
} 

		int RNG(){

			int sayi;
			srand(time(NULL));		
			sayi = rand()%10+1;/*Tutulan sayinin 0-10 arasinda olmasinin saglanmasi*/
			return sayi;
		}

		int calculate_the_difference(int sayi2, int thmn){

			double fark;

			/*Tahmin ile tutulan sayi arasindaki farkin hesaplanmasi 
			ve mutlak degerinin alinmasi*/
			fark = sayi2 - thmn;
			fark = abs(fark);

		
			return (int) fark;
		
		}

		void warn_the_player(int uzaklik){	
			
			/*Farkin buyuklugu veya kucuklugune gore uyari verilmesi*/
			if(uzaklik>=5)
				printf("You are too far from the number\n");
			
			else if(uzaklik>=3 && uzaklik<5)
				printf("You are far from the number\n");
			
			else 
				printf("You are close to the number\n");

		}
/*____________________________________________________________________________________*/

/*                  HW03_Kevser_Yolcu_131044072_part1.c                                     */
/*____________________________________________________________________________________*/		

