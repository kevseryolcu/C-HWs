/*____________________________________________________________________*/

/*                  HW10-11 Kevser Yolcu 131044072 
 * 							Part1.c           						  */
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
#include<stdlib.h>
#include<string.h>
#include "Part1.h"

/*reads all appointments in the records file into a dynamicaly 
 * allocated fully-filled array and returns the array*/

Appointment_t* getRequests(const Files_t* files, int* size)
{
	FILE* fbinp;
	Appointment_t* bin;
	int i = 0;
	
	
	fbinp = fopen(files->records_file_n, "rb");
	
	fread(size, sizeof(int), 1, fbinp);
	
	bin = (Appointment_t*) calloc(*size,sizeof(Appointment_t));
	
	while(fread(&bin[i++], sizeof(Appointment_t), 1, fbinp) > 0);
		
	fclose(fbinp);

	return bin;
}


/*writes all appointments in the input array to readable records
 * file in described format*/
void write_appointments(Appointment_t appointments[], int size, 
						const Files_t* files)
{
	int i;
	FILE* outp;
	
	outp = fopen(files->readable_records_file_n, "w");
	
	fprintf(outp, "<Size>%d</Size>\n<Records>\n", size);
	
	for(i = 0; i < size; ++i)
	{
		fprintf(outp, "	<Appointment>\n	");
		fprintf(outp, "	<app_id>%d</app_id>\n	", appointments[i].app_id);
		fprintf(outp, "	<patient_id>%d</patient_id>\n	", appointments[i].patient_id);
		fprintf(outp, "	<hour>%d</hour>\n	", appointments[i].hour);
		fprintf(outp, "</Appointment>\n");
	}
	
	fprintf(outp, "</Records>");
	
	fclose(outp);
}

/*takes the arguments of main() as input parameter and , using globally 
 * defined defaults when necessary, returns used input file names and 
 * working hours as output parameters*/
void get_main_arguments(int argc, char* argv[], Working_hours_t* hours, 
						Files_t* files)
{
	int i = 1;
	
	while(i<argc)
	{
		if(strcmp(argv[i],"-r")==0)
			files->records_file_n=argv[i+1];
		if(strcmp(argv[i],"-p")==0)
			files->patients_file_n = argv[i+1];
		if(strcmp(argv[i],"-d")==0)
			files->delete_file_n = argv[i+1];		
		if(strcmp(argv[i],"-x")==0)
			files->readable_records_file_n = argv[i+1];		
		if(strcmp(argv[i],"-c")==0)
			files->accepted_appo_file_n = argv[i+1];
		if(strcmp(argv[i],"-t")==0)
			files->parameters_file_n = argv[i+1];
		if(strcmp(argv[i],"-s")==0)
			hours->start = atoi(argv[i+1]);
		if(strcmp(argv[i],"-e")==0)
			hours->end = atoi(argv[i+1]);
		++i;
	}
		
}						
/*writes file names and working hours to parameters file in described format*/
void print_parameters(const Files_t* files, const Working_hours_t* hours)
{
	FILE* inp;
	
	inp = fopen(files->parameters_file_n, "w");
	
	fprintf(inp, "%s\n%s\n%s\n%s\n%s\n%s\n%d\n%d\n", 
		    files->records_file_n,
		    files->patients_file_n,
		    files->delete_file_n,
		    files->readable_records_file_n,
		    files->accepted_appo_file_n,
		    files->parameters_file_n,
		    hours->start,
		    hours->end);
	
	fclose(inp);
		
}
/*____________________________________________________________________*/

/*                  HW10-11 Kevser Yolcu 131044072 
 * 							Part1.c           						  */
/*____________________________________________________________________*/		
