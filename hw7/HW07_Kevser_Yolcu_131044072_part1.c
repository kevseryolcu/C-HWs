/*______________________________________________________________________

                  HW07_Kevser_Yolcu_131044072_part1.c                  
              Kevser Yolcu tarafindan 12.04.2015'te yazildi                        
                                                                                    
                                  Aciklama                                          
		Konsoldan alinan bir stringin icinde yine konsoldan alinan 
   	bir stringi arama 
                 
     Alinan Degerler:                                                                 
 	  	-Aranan ve icinde aranacak olan iki string                                                                      

     Cikan Degerler:                                                  
         -Aranan stringin diger string icerisinde kac defa bulundugu                 

                              Icerik                                 
____________________________________________________________________*/


#include<stdio.h>
#include<string.h>
#define STR_SIZE 100/*stringlerin max boyutu*/

/* Aranan stringin diger string icerisinde kac defa bulundugunu 
 * bulan fonksiyon												*/
int char_number(const char *string, const char *wish_to_find);

/*bir stringin boyutunu recursive yoluyla bulan ve donduren fonksiyon*/
int find_size(const char *string);

int main()
{
	int occ;
	char str[STR_SIZE];
	char wt_find[STR_SIZE];
	
	printf("Arama yapacagınız stringi -birinci stringi- giriniz. \n");
	fgets(str, STR_SIZE, stdin);	
	
	printf("Bulunacak stringi -ikinci stringi- giriniz. \n");
	fgets(wt_find, STR_SIZE, stdin);
	
	/*tekrar sayisini bulan fonksiyonun cagirilmasi*/		
	occ = char_number(str, wt_find);
	
	printf("Ikinci string birincinin icinde %d adet bulunmaktadir. \n", occ);
	
	return 0;
}

/* Aranan stringin diger string icerisinde kac defa bulundugunu 
 * bulan fonksiyon												*/
int find_size(const char *string)
{
	int res = 1;
	
	/*fgets fonksiyonu '\n' i de okudugundan "!=  '\n' " kullandım*/
	if(string[res - 1] != '\0' && string[res - 1] != '\n')
		res += find_size(&string[res]);

	return res;
}

/*bir stringi diger string icinde arayan ve bulunma sayisini donduren fonksiyon*/
int char_number(const char *string, const char *wish_to_find)
{
	int sizew,
		sizes,
		i = 0,
		j = 0,
		count = 0;

/*stringlerin boyutunun bulunmasi*/	
	sizew = find_size(wish_to_find);
	sizes = find_size(string);

	if(sizew == 2)
	{
		for(i=0; string[i] != '\0' && string[i] != '\n'; ++i){
			if(wish_to_find[j] == string[i])
				count++;
		}
	}
	else if(sizes >= sizew){	
		
		while(string[i] != '\0' && string[i] != '\n')
		{
			if(wish_to_find[j] != string[i])
				++i;
			
			if(wish_to_find[j] == string[i]){
				++j;
				++i;
			
				if( wish_to_find[j] != string[i] ){
					j = 0;
					++i;
				}
				if(j == sizew - 2){
					j = 0;
					++count;
					++i;
				}
			}
		}
	}
	else
		count = -1;		
	
	return count;
}

/*______________________________________________________________________

                 HW07_Kevser_Yolcu_131044072.part1.c                 
______________________________________________________________________*/		

