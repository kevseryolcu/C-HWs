
/*____________________________________________________________________*/

/*                  HW10-11 Kevser Yolcu 131044072 
 * 							Part1.h           						  */
/*              Kevser Yolcu tarafindan 21 Mayis 2015'te yazildi      */
/*                                                                    */
/*                                  Aciklama                          */
/* 		Bir binary dosyadan verilerin alinip arraya atilmasi ,
 *  bu arraydeki verilerin xml formatinda dosyaya yazilmasi,
 *  main argumanlari ile dosya isimlerinin ve calisma 
 *  saatlerinin degistirilmesi, dosyayayazdirilmasi				      */
/*                            			                              */
/*____________________________________________________________________*/

typedef struct{
	int app_id;
	int patient_id;
	int hour;
}Appointment_t;

typedef struct{
	int start;
	int end;	
}Working_hours_t;

typedef struct{
	char* records_file_n ;
	char* patients_file_n ;
	char* delete_file_n ;
	char* readable_records_file_n ;
	char* accepted_appo_file_n ;
	char* parameters_file_n ;
}Files_t;


typedef struct node_t{
	int app_id;
	int patient_id;
	char name[50];
	char* history;
	int hour;
	struct node_t* next;
}node_t;


/*reads all appointments in the records file into a dynamicaly 
 * allocated fully-filled array and returns the array*/
extern Appointment_t* getRequests(const Files_t* files, int* size);


/*writes all appointments in the input array to readable records
 * file in described format*/
extern void write_appointments(Appointment_t appointments[], int size, 
						const Files_t* files);
						
						
/*takes the arguments of main() as input parameter and , using globally 
 * defined defaults when necessary, returns used input file names and 
 * working hours as output parameters*/
extern void get_main_arguments(int argc, char*argv[], Working_hours_t* hours, 
						Files_t* files);
						
/*writes file names and working hours to parameters file in described format*/						
extern void print_parameters(const Files_t* files, const Working_hours_t* hours);

/*____________________________________________________________________*/

/*                  HW10-11 Kevser Yolcu 131044072 
 * 							Part1.h           						  */
/*____________________________________________________________________*/



