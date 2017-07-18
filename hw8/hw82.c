#include<stdio.h>
#define PEOPLE "People.txt"
#define AREGS "AppointmentReqs.txt"
#define APPONT "Appointments.txt"

typedef enum
	{M,F}
Gender_t;

typedef enum
	{JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER,
	 OCTOBER, NOVEMBER, DECEMBER}
Months_t;

typedef struct{
	 int first_half;
	 int second_half;
}TCId_no_t;

typedef struct{
	TCId_no_t id_no;
	char name[30];
	char surname[30];
	Gender_t gender;
}People_t;

typedef struct{
	int hour;
	int minute;
}Time_t;

typedef struct{
	int year;
	Months_t month;
	int day;
	Time_t time;
}Date_t;

typedef struct{
	People_t people;
	Date_t date;
}Appointment_t;

int get_people(const char *file_name, People_t people[], int max_size);
int get_appointments(const char *file_name, Appointment_t appointments[],
 					 int max_size);
void write_names(Appointment_t appointments[], int size_app, 
				 const People_t people[], int size_people);
int check_appointments(Appointment_t appointments[], int size);
void sort_appointments(Appointment_t appointments[], int size);
void write_appointments(const char *file_name, Appointment_t appointments[],
 						int size);

int main()
{
	People_t people[100];
	int numb_peo;
	char str[20];
	//numb_peo = get_people(PEOPLE, people, 3);
	//printf("%d\n", numb_peo);
	FILE *inp;
	inp = fopen(PEOPLE,"r");
	fscanf(inp,"%s",str);
	//printf("%c\n", str[1]);
	return 0;
}

int get_people(const char *file_name, People_t people[], int max_size)
{
	int i, status = 1;
	char str[5];
	FILE *inp;
	inp = fopen(file_name,"r");
	for(i=0; i<max_size && status > 0; ++i){
		status = fscanf(inp,"%d %s %s",//%c
						&(people[i].id_no.first_half), /*&(people[i].id_no.second_half),*/
						&(people[i].name), &(people[i].surname));//, &str;
						printf("%d st %d  id1 %d  id2 %d\n",i,status,people[i].id_no.first_half,people[i].id_no.second_half);
	}
	
	fclose(inp);
	return i;
}


