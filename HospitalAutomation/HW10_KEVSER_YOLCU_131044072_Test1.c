/*____________________________________________________________________*/

/*                  HW10-11 Kevser Yolcu 131044072 
 * 							Test1.c           						  */
/*              Kevser Yolcu tarafindan 21 Mayis 2015'te yazildi      */
/*                                                                    */
/*                                  Aciklama                          */
/* 		Bir binary dosyadan verilerin alinip arraya atilmasi ,
 *  bu arraydeki verilerin xml formatinda dosyaya yazilmasi,
 *  main argumanlari ile dosya isimlerinin ve calisma 
 *  saatlerinin degistirilmesi, dosyayayazdirilmasi				      */
/*                            			                              */
/*____________________________________________________________________*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Part1.h"

Working_hours_t w_hours = {9, 17};

Files_t file = {"Records.bin","Patients.xml","Delete.txt","Records.xml",
				"Appointments.csv","Parameters.txt"};

int main(int argc, char* argv[])
{

	Appointment_t* result;
	int size ;

	get_main_arguments(argc, argv, &w_hours, &file);
	
	print_parameters(&file, &w_hours);
	
	result = getRequests(&file, &size);

	write_appointments(result, size, &file);
	
	return 0;
}
/*____________________________________________________________________*/

/*                  HW10-11 Kevser Yolcu 131044072 
 * 							Test1.c           						  */
/*____________________________________________________________________*/
