/*____________________________________________________________________________________*/

/*                  HW03_Kevser_Yolcu_131044072.part2.c                               */
/*              Kevser Yolcu tarafindan 6 Mart 2015'te yazildi                        */
/*                                                                                    */
/*                                  Aciklama                                          */
/*40 ile 80 feet arasinda rastgele bir yukseklikten birakilan bir topun yuksekligini 
 yine 0.4 ile 0.8 arasında rastgele secilen bir kuculme miktariyla hesaplayan ve 
 yukseklik 1 feete dusene kadar olan yukseklikleri ve aldigi toplam yol miktarini 
 hesaplayan ve bunlari hem konsola hem dosyaya yazdiran program						  */


/*                             Icerik                                                 */
/*____________________________________________________________________________________*/


#include<stdio.h>

#define FEET 1.0
#define TOUR 2.0
#define PAYDA 100.0

/*Fonksiyonlarin tanimlanmasi*/
double calculate_the_new_height(double fark , int ilk_yukseklik);
double calculate_the_vertical_distance(int yukseklik , double yeni_yukseklik);
void report(int numb_bounce , double rebouncing_height , double total_vertical_distance, FILE *inp);

int main(void)
{

	int 	first_height,
			sayi,
			count;
	double  ratio,
			new_height,
			total_distance;
	
	/*Sonuclarin yazilacagi dosyanin acilmasi*/
	FILE *fp;
	
	fp = fopen("Result_Table.txt", "w");

	/*Rastgele ilk yuksekligin secilmesi*/
	srand(time(NULL));
	first_height = rand()%30 + 10;
		
	/*Rastgele azalma oraninin secilmesi*/
	sayi = rand()%40 + 40;
	ratio = sayi / PAYDA;

	/*Ikinci yuksekligin hesaplanmasi dongunun icinde kullanilmadi cunku
	  bu adim dongu icinde kayboluyordu			                        */
	new_height = first_height;
    total_distance = calculate_the_vertical_distance(first_height , 0);

	count=0;

	fprintf(fp , "No -- The Rebouncing Height -- The Total Vertical Distance\n");

	printf("No -- The Rebouncing Height -- The Total Vertical Distance\n");	

	do{
	
	report(count , new_height , total_distance, fp);

	/*Yeni yuksekliklerin bulunmasini saglayan fonksiyonun cagirilmasi*/
	new_height = calculate_the_new_height(ratio , new_height);

	/*Toplam yuksekliklerin bulunmasini saglayan fonksiyon cagirilmasi*/
	total_distance = calculate_the_vertical_distance(total_distance , new_height);
	
	count += 1;/*ziplama sayisinin hesaplanmasi*/

	

	}while(new_height > FEET);
	
	fclose(fp);



	return 0;
}

/*Yeni yuksekliklerin bulunmasini saglayan fonksiyon*/
double calculate_the_new_height(double fark , int ilk_yukseklik)
{
	return (ilk_yukseklik*fark);

}

/*Toplam yuksekliklerin bulunmasini saglayan fonksiyon*/
double calculate_the_vertical_distance(int yukseklik , double yeni_yukseklik)
{
	return (yukseklik + yeni_yukseklik*TOUR);

}

/*Sonuclarin konsola ve dosyaya bastirilmasi*/
void report(int numb_bounce , double rebouncing_height , double total_vertical_distance, FILE *inp)
{
	
	
	fprintf(inp , "%d	%f		%f\n" , numb_bounce , rebouncing_height , total_vertical_distance);


	printf("%d	%f		%f\n" , numb_bounce , rebouncing_height , total_vertical_distance);

}
/*____________________________________________________________________________________*/

/*                  HW03_Kevser_Yolcu_131044072.part2.c                               */
/*____________________________________________________________________________________*/


