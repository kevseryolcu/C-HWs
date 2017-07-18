/*______________________________________________________________________

                  HW07_Kevser_Yolcu_131044072_part3.c                  
              Kevser Yolcu tarafindan 12.04.2015'te yazildi                        
                                                                                    
                                  Aciklama                                          
		Verilen labirentte yolunu bulan program 
                 
     Alinan Degerler:                                                                 
 	  	-Labirentin bulundugu txt                                                                     

     Cikan Degerler:                                                  
         -Bulunan yol haritasi                

                              Icerik                                 
____________________________________________________________________*/

#include<stdio.h>
#include<stdbool.h>
#define COL_SIZE 5/*Labirentin kaca kaclik bir matris oldugu*/
#define INP_FILE "table.txt"/*labirentin okundugu txt*/

/*adimlarin uygunlugunu belirten enumeration*/
typedef enum
	{notavailable, available, right_down}
Grid_t;

/*labirenti txt den okuyup arraya atan fonksiyon*/
void read_table(FILE *input_file, Grid_t table[][COL_SIZE]);

/*labirentteki adimlari konsola yazan fonksiyon*/
void print_path(char path[][COL_SIZE], int n);

/*labirentteki adimlari bulan fonksiyon*/
bool find_path(Grid_t table[][COL_SIZE], char path[][COL_SIZE],
			   int size, int location_x, int location_y);
			   
int main()
{	
	
	Grid_t table[COL_SIZE][COL_SIZE];
	char path[COL_SIZE][COL_SIZE];
	int i,j;
	bool k;
	FILE *inp;
	/*dosyanin acilmasi*/
	inp = fopen(INP_FILE , "r");
	
	/*labirentin arraya atilmasi*/
	read_table(inp, table);
	
	for(i=0; i < COL_SIZE; ++i){
		for(j=0; j < COL_SIZE; ++j)
			printf("%c", table[i][j]);
		printf("\n");
	}
	
	/*labirentteki adimlarin bulunmasi*/
	 k = find_path(table, path, COL_SIZE, i = 0, j = 0);

	printf("\n%d\n", k);
	
	print_path(path, COL_SIZE);
	
	/*dosyanin kapatilmasi*/
	fclose(inp);
	
	return 0;
}

/*labirenti txt den okuyup arraya atan fonksiyon*/
void read_table(FILE *input_file, Grid_t table[][COL_SIZE])
{
	int i,j;

	
	for(i = 0; i < COL_SIZE+1; ++i)
		for(j = 0; j < COL_SIZE+1; ++j){
			fscanf(input_file, "%c", &table[i][j]);
		}

}

/*labirentteki adimlari bulan fonksiyon*/
bool find_path(Grid_t table[][COL_SIZE], char path[][COL_SIZE],
			   int size, int location_x, int location_y)
{
	bool k;
	int i = location_x,
		j = location_y;

	if(i < size && j < size){	
		if(table[i][j] == 2){
			path[i][j] = '*';

			k =find_path(table, path, size, i+1, j+1);
		}
		else if(table[i][j] == 1){
			path[i][j] = '*';
			if(table[i+1][j] == 1 || table[i+1][j] == 2){
				k = find_path(table, path, size, i+1, j);
			}
			else{
				path[i+1][j] = ' ';
				k = false;
			}
			
			
			if(table[i][j+1] == 1 || table[i][j+1] == 2){
				k = find_path(table, path, size, i, j+1);
			}
			else{
				path[i][j+1] = ' ';
				k = false;
				
			}


		}
		else{
			path[i][j] = ' ';
			k = false;	
		
		}	

	}
	return k;		   
}
void print_path(char path[][COL_SIZE], int n)
{
	int i, j;
	for(i=0; i < n; ++i){
		for(j=0; j < n; ++j)
			printf("%c", path[i][j]);
		printf("\n");
	}	
	
}
/*______________________________________________________________________

                 HW07_Kevser_Yolcu_131044072.part3.c                 
______________________________________________________________________*/
