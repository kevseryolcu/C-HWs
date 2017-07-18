/*____________________________________________________________________________________*/

/*                  HW02_Kevser_Yolcu_131044072.part2.c                               */
/*              Kevser Yolcu tarafindan 1 Mart 2015'te yazildi                        */
/*                                                                                    */
/*                                  Aciklama                                          */
/*Verilen uc ogrencinin kredilerinden gelen katkilarin ve harf notlarinin hesaplanmasi*/
/*   Alinan Degerler:                                                                 */                    
/* Ogrencilerin                                                                       */
/*            -İsimleri ve Soyisimleri                                                */
/*            -1.Vize                                                                 */
/*            -2.Vize                                                                 */
/*            -Final                                                                  */
/*   Cikan Degerler:                                                                  */
/*  Ogrencilerin                                                                      */
/*            -Harf Notlari                                                           */
/*            -Kredilerinden Gelen Katkilari                                          */

/*                             Icerik                                                 */
/*____________________________________________________________________________________*/

#include <stdio.h>
#define YUZDE_MID 0.3/*Vizelerdenlerden gelen yuzde*/
#define YUZDE_FIN 0.4/*Finallerden gelen yuzde*/
#define DERS_KREDISI 3.0/*Bir dersin kredisi*/
#define TOP_KREDI 20.0/*Bir dönemde alinan toplam kredi sayisi*/

/*Fonksiyonlarin tanitilmasi*/

/*Vizeler ve finalden gelen notlarin ortalamasini alan fonksiyon*/
double ortalama (int midterm1, int midterm2, int final);

/*Ortalama notlara harf notlarini atayan fonksiyon*/
char notlandirma(double not);

/*Harflere karsilik gelen kredileri atayan fonksiyon*/
int harflerin_kredi_karsiligi(char harf_kredisi);

/*Sonucu yazdiran fonksiyon*/
void PrintResult(char name1, char surname1, double ort_not1 , char grade1, double contrib1,
				 char name2, char surname2, double ort_not2 , char grade2, double contrib2,
				 char name3, char surname3, double ort_not3 , char grade3, double contrib3,
				 char name4, char surname4, double ort_not4 , char grade4, double contrib4,
				 char name5, char surname5, double ort_not5 , char grade5, double contrib5);
int main()
{
	/*Degiskenlerin ve dosyalarin tanitilmasi*/
	char harf_notu1, isim1, soyisim1,
		 harf_notu2, isim2, soyisim2,
 		 harf_notu3, isim3, soyisim3,
		 harf_notu4, isim4, soyisim4,
		 harf_notu5, isim5, soyisim5,
		 char_cop;
	
	int kredi1 , kredi2 , kredi3 , kredi4 , kredi5;

	double contribution1 , ort_not1,
		   contribution2 , ort_not2,
		   contribution3 , ort_not3,
		   contribution4 , ort_not4,
		   contribution5 , ort_not5;

	int student1Mid1 , student1Mid2 , student1Final,
		student2Mid1 , student2Mid2 , student2Final,
		student3Mid1 , student3Mid2 , student3Final,
		student4Mid1 , student4Mid2 , student4Final,
		student5Mid1 , student5Mid2 , student5Final;

 	FILE *iptr;

	/*Dosyanin acilmasi*/
	iptr = fopen("Students.txt" , "r");

	/*Dosyadan degerlerin okunmasi*/
	fscanf(iptr , "%c%c%d%d%d%c%c%c%d%d%d%c%c%c%d%d%d%c%c%c%d%d%d%c%c%c%d%d%d" ,
		   &isim1 , &soyisim1 , &student1Mid1 , &student1Mid2 , &student1Final, &char_cop,
		   &isim2 , &soyisim2 , &student2Mid1 , &student2Mid2 , &student2Final, &char_cop,
		   &isim3 , &soyisim3 , &student3Mid1 , &student3Mid2 , &student3Final, &char_cop,
		   &isim4 , &soyisim4 , &student4Mid1 , &student4Mid2 , &student4Final, &char_cop,
		   &isim5 , &soyisim5 , &student5Mid1 , &student5Mid2 , &student5Final);


	/*1. ogrenci icin fonksiyonlarla cıktıların bulunmasi*/
	ort_not1 = ortalama(student1Mid1 , student1Mid2 , student1Final);

	harf_notu1 = notlandirma(ort_not1);

	kredi1 = harflerin_kredi_karsiligi(harf_notu1);

	contribution1 = kredi1 * DERS_KREDISI/TOP_KREDI ;


	/*2. ogrenci icin fonksiyonlarla cıktıların bulunmasi*/
	ort_not2 = ortalama(student2Mid1 , student2Mid2 , student2Final);

	harf_notu2 = notlandirma(ort_not2);

	kredi2 = harflerin_kredi_karsiligi(harf_notu2);

	contribution2 = kredi2 * DERS_KREDISI/TOP_KREDI ;


	/*3. ogrenci icin fonksiyonlarla cıktıların bulunmasi*/
	ort_not3 = ortalama(student3Mid1 , student3Mid2 , student3Final);

	harf_notu3 = notlandirma(ort_not3);

	kredi3 = harflerin_kredi_karsiligi(harf_notu3);

	contribution3 = kredi3 * DERS_KREDISI/TOP_KREDI ;


	/*4. ogrenci icin fonksiyonlarla cıktıların bulunmasi*/
	ort_not4 = ortalama(student4Mid1 , student4Mid2 , student4Final);

	harf_notu4 = notlandirma(ort_not4);

	kredi4 = harflerin_kredi_karsiligi(harf_notu4);

	contribution4 = kredi4 * DERS_KREDISI/TOP_KREDI ;


	/*5. ogrenci icin fonksiyonlarla cıktıların bulunmasi*/
	ort_not5 = ortalama(student5Mid1 , student5Mid2 , student5Final);

	harf_notu5 = notlandirma(ort_not5);

	kredi5 = harflerin_kredi_karsiligi(harf_notu5);

	contribution5 = kredi5 * DERS_KREDISI/TOP_KREDI ;
	

	/*Sonuclarin ekrana ve dosyaya yazdirilmasi*/
	PrintResult(isim1 , soyisim1 , ort_not1 , harf_notu1 , contribution1,
				isim2 , soyisim2 , ort_not2 , harf_notu2 , contribution2,
				isim3 , soyisim3 , ort_not3 , harf_notu3 , contribution3,
				isim4 , soyisim4 , ort_not4 , harf_notu4 , contribution4,
				isim5 , soyisim5 , ort_not5 , harf_notu5 , contribution5);


	/*Dosyanin kapatilmasi*/
	fclose(iptr);

	return 0;
}

	double ortalama(int midterm1, int midterm2, int final)
	{

	/*Degiskenlerin tanitilmasi*/
	double mid1;
	double mid2;
	double fin;
	double sonuc;

		/*Sinavlardan gelen oranlarin hesaplanmasi*/
		mid1 = midterm1 * YUZDE_MID;
		mid2 = midterm2 * YUZDE_MID;
		fin = final * YUZDE_FIN;

		/*Ortalama notun hesaplanmasi*/
		sonuc = mid1 + mid2 + fin;

	return sonuc;
	}


	char notlandirma(double not)
	{
	
		/*ortalama nota gore harf notunun atanmasi*/
		if(not<=100.0 && not>=85.0)
			return 'A';

		else if(not<=84.0 && not>=70.0)
			return 'B';

		else if(not<=69.0 && not>=65.0)
			return 'C';

		else if(not<=64.0 && not>=40.0)
			return 'D';

		else 
			return 'F';

	}


	int harflerin_kredi_karsiligi(char harf_kredisi)
	{
		int sonuc;

		/*Harf notlarina gore kredilerin atanmasi*/
		switch(harf_kredisi)
		{
		case 'A': sonuc=4;
			  	  break;

		case 'B': sonuc=3;
			  	  break;

		case 'C': sonuc=2;
			  	  break;

		case 'D': sonuc=1;
			 	  break;

		case 'F': sonuc=0;
			 	  break;	
		}
	return sonuc;
	}

void PrintResult(char name1, char surname1, double ort_not1 , char grade1, double contrib1,
				 char name2, char surname2, double ort_not2 , char grade2, double contrib2,
				 char name3, char surname3, double ort_not3 , char grade3, double contrib3,
				 char name4, char surname4, double ort_not4 , char grade4, double contrib4,
				 char name5, char surname5, double ort_not5 , char grade5, double contrib5)
	{
		/*Dosyanin tanitilmasi*/
		FILE *optr;
		
		/*Dosyanin acilmasi*/
		optr=fopen("Grades.txt" , "w");

		/*sonuclarin dosyaya bastırılmasi*/
		fprintf(optr , "%c %c %c %.2f\n" , name1 , surname1 , grade1 , contrib1);
		fprintf(optr , "%c %c %c %.2f\n" , name2 , surname2 , grade2 , contrib2);
		fprintf(optr , "%c %c %c %.2f\n" , name3 , surname3 , grade3 , contrib3);
		fprintf(optr , "%c %c %c %.2f\n" , name4 , surname4 , grade4 , contrib4);
		fprintf(optr , "%c %c %c %.2f\n" , name5 , surname5 , grade5 , contrib5);
	
		/*sonuclarin ekrana bastırılmasi*/
		printf("Name Surname AveragePoint Grade Contribution\n");

		printf(" %c	%c	%.2f	  %c	%.2f\n" , name1 , surname1 , ort_not1 , grade1 , contrib1);
		printf(" %c	%c	%.2f	  %c	%.2f\n" , name2 , surname2 , ort_not2 , grade2 , contrib2);
		printf(" %c	%c	%.2f	  %c	%.2f\n" , name3 , surname3 , ort_not3 , grade3 , contrib3);
		printf(" %c	%c	%.2f	  %c	%.2f\n" , name4 , surname4 , ort_not4 , grade4 , contrib4);
		printf(" %c	%c	%.2f	  %c	%.2f\n" , name5 , surname5 , ort_not5 , grade5 , contrib5);

		/*Dosyanin kapatilmasi*/
		fclose(optr);
	}

/*____________________________________________________________________________________*/

/*                  HW02_Kevser_Yolcu_131044072.part2.c                               */
/*____________________________________________________________________________________*/

