
/*______________________________________________________________________

                  HW07_Kevser_Yolcu_131044072_part2.c                  
              Kevser Yolcu tarafindan 12.04.2015'te yazildi                        
                                                                                    
                                  Aciklama                                          
		-Basamak sayisi ve bir adimda en fazla kac basamak 
	cikilabilecegi verilen bir merdiveni kac farklı sekilde 
	cikilabilecegini bulan program
                 
     Alinan Degerler:                                                                 
 	  	-Basamak sayisi
 	  	-Bir adimda cikilabilecek maximum basamak sayisi(macro)                                                                      

     Cikan Degerler:                                                  
         -Merdivenin kac farkli sekilde cikilabildigi                 

                              Icerik                                 
____________________________________________________________________*/


#include<stdio.h>
#define MAX_A_STEP 2/*Bir adimda cikilabilecek maximum basamak sayisi*/

/*Kombinasyon hesaplayan fonksiyon*/
int combination(int n, int k);

/*Merdivenin kac farkli sekilde cikilabildigini bulan fonksiyonu 
 cagiran fonksiyon*/
int ways (int n);

/*Merdivenin kac farkli sekilde cikilabildigini bulan fonksiyon*/
int way_rec(int n, int k);

int main()
{
	int how_many,
		n;
		
	printf("Basamak sayisini giriniz. \n");
	scanf("%d", &n);
	
	how_many = ways(n);
	
	printf("Merdiveni %d farkli sekilde cikabilirsiniz.\n", how_many);
	
	return 0;
}

/*Merdivenin kac farkli sekilde cikilabildigini bulan fonksiyonu 
 cagiran fonksiyon*/
int ways (int n)
{
	int k = 0,
		result;
	
	result = way_rec(n, k);
		
	return result;	
}

/*Merdivenin kac farkli sekilde cikilabildigini recursive olarak 
  bulan fonksiyon*/

int way_rec(int n, int k)
{
	int res;
	
	if(n >= k && k <= MAX_A_STEP)
		res = combination(n,k) + way_rec(n-1, k+1);
	else
		res = 0;
		
	return res;	
}

/*Kombinasyon hesaplayan fonksiyon(recursive)*/
int combination(int n, int k)
{
	int total = 1;
	
	if(k != 0 && n >= k)
		total = ( (n) * combination(n - 1, k - 1) )/k;

	return total;
}
/*______________________________________________________________________

                 HW07_Kevser_Yolcu_131044072.part2.c                 
______________________________________________________________________*/
