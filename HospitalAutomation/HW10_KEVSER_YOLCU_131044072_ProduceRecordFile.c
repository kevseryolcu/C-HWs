/*____________________________________________________________________*/

/*                  HW10-11 Kevser Yolcu 131044072 
 * 							ProduceRecordFile.c           			  */
/*              Kevser Yolcu tarafindan 19 Mayis 2015'te yazildi      */
/*                                                                    */
/*                                  Aciklama                          */
/* Bir binary dosyaya structure ın elemanlarini yazma		          */
/*   Alinan Degerler:                                                 */                    
/* 		-Dosyanin ismi                                      		  */
/*      -Structure elemanlari                                         */

/*   Cikan Degerler:                                                  */
/*            -Binary Dosya                 						  */

/*                             Icerik                                 */
/*____________________________________________________________________*/


#include<stdio.h>
#include<stdlib.h>
#include "Part1.h"

int sz[] = {4};

Files_t file = {"Records.bin","Patients.xml","Delete.txt","Records.xml",
				"Appointments.csv","Parameters.txt"};

Working_hours_t w_hours = {9, 17};

int main(int argc, char* argv[])//
{
	Appointment_t* arr;
	Appointment_t* xarr;
	
	get_main_arguments(argc, argv, &w_hours, &file);
	
	arr = malloc(4*sizeof(Appointment_t));
	xarr = malloc(4*sizeof(Appointment_t));
	
	int i;	
	int sz2[1];/*binary file a yazilan verilerin sayisi*/
	
	FILE* binp;
	binp = fopen(file.records_file_n, "wb");
	/*binary file yazmak icin acilmasi*/
	
	if(binp == NULL)
		printf("File couldn't be opened to write\n");
	
	/*structure arrayinin doldurulmasi*/	
	arr[0].app_id = 8;
	arr[0].patient_id = 2;
	arr[0].hour =11;

	arr[1].app_id = 3;
	arr[1].patient_id = 5;
	arr[1].hour =19;


	arr[2].app_id = 11;
	arr[2].patient_id = 2;
	arr[2].hour =14;

	arr[3].app_id = 203;
	arr[3].patient_id = 20;
	arr[3].hour =11;

	fwrite(sz, sizeof(int), 1, binp);/*binary filea ondan sonra gelecek 
									olanlarin eleman sayisinin yazilmasi*/
	fwrite(arr, sizeof(Appointment_t)*sz[0] , 1, binp);
	/*arrayin dosyaya yazilmasi*/
	
	fclose(binp);
	
	binp = fopen(file.records_file_n, "rb");
	/*dosyanin okunmak icin acilmasi*/
	
	if(binp == NULL)
		printf("File couldn't be opened to read\n");
	
	/*dosyanin okunmasi*/	
	fread(sz2, sizeof(int)*1, 1, binp);	
	fread(xarr, 4*sizeof(Appointment_t) , 1, binp);
	
	fclose(binp);/*dosyanin kapatilmasi*/
	
	printf("size = %d\n", sz2[0]);
	
	for(i=0; i<sz[0]; ++i){
		printf("\n%d\n%d\n%d\n\n", xarr[i].app_id, xarr[i].patient_id, 
								   xarr[i].hour);
	}

	return 0;
}
/*____________________________________________________________________*/

/*                  HW10-11 Kevser Yolcu 131044072 
 * 							ProduceRecordFile.c           			  */
/*____________________________________________________________________*/		

