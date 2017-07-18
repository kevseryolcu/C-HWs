/*____________________________________________________________________________________*/

/*                  HW02_Kevser_Yolcu_131044072_part1.c                               */
/*              Kevser Yolcu tarafindan 1 Mart 2015'te yazildi                        */
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
int WarnThePlayer(int mutlak);/*Kullanicinin cevabina gore uyari veren fonksiyon*/
int CalculatesTheDifference(int sayi2, int thmn);/*Tutulan sayi ile tahmin
												 arasindaki farki bulan fonksiyon*/

int main(){
	/*Degiskenlerin tanitilmasi*/
	int tahmin;
	int tutulan_sayi;
	int yakinlik2;
	int karsilastirma2;

		/*fonksiyonun cagirilmasi*/
		tutulan_sayi = RNG();
		
		/*Kullanicidan tahmin istenmesi*/
		printf("Come on guess the number-\n");
		scanf("%d",&tahmin);
		
		/*Fonksiyon ile farkin bulunmasi*/
		yakinlik2 = CalculatesTheDifference(tutulan_sayi,tahmin);
		
		/*Farkin karsilastirilmasi*/
		if(yakinlik2==0)
			printf("You win, congratulations\n");
			
		else if(yakinlik2!=0){

			karsilastirma2 = WarnThePlayer(yakinlik2);
		
			printf("Your last chance, guess the number again-\n");
			scanf("%d",&tahmin);

			yakinlik2 = CalculatesTheDifference(tutulan_sayi,tahmin);

			if(yakinlik2==0)
				printf("You win, congratulations\n");
			
			else 
				printf("Game over\n");
		}

	return 0;
} 

		int RNG(){

			int sayi;
			srand(time(NULL));		
			sayi = rand()%11;/*Tutulan sayinin 0-10 arasinda olmasinin saglanmasi*/
			return sayi;
		}

		int CalculatesTheDifference(int sayi2, int thmn){

			double fark;

			/*Tahmin ile tutulan sayi arasindaki farkin hesaplanmasi 
			ve mutlak degerinin alinmasi*/
			fark = sayi2 - thmn;
			fark = abs(fark);

		
			return (int) fark;
		
		}

		int WarnThePlayer(int uzaklik){	
			
			/*Farkin buyuklugu veya kucuklugune gore uyari verilmesi*/
			if(uzaklik>=5)
				printf("You are too far from the number\n");
			
			else if(uzaklik>=3 && uzaklik<5)
				printf("You are far from the number\n");
			
			else 
				printf("You are close to the number\n");

			return 0;
		}
/*____________________________________________________________________________________*/

/*                  HW02_Kevser_Yolcu_131044072.part1.c                               */
/*____________________________________________________________________________________*/		

