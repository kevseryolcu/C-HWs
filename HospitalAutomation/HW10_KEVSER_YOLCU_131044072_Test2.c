/*____________________________________________________________________*/

/*                  HW10-11 Kevser Yolcu 131044072 
 * 							Test2.c           						  */
/*               24 Mayis 2015 by Kevser Yolcu     					 */
/*                                                                    */
/*   Build a linked-list holding the valid appointment records in 
 * this array
 *   Handle the following operations on the link-list :
      -Adding patient history, taken from the patients file (text file), 
* 	 to each appointment in the list 
	  -Deleting a list of canceled appointments, taken from a delete file
 *  (text file)
 * 	  -Deallocating the dynamic data  								  */
/*                            			                              */
/*____________________________________________________________________*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Part1.h"
#include "Part2.h"

Working_hours_t w_hours = {14, 21};

Files_t file = {"Records.bin","Patients.xml","Delete.txt","Records.xml",
				"Appointments.csv","Parameters.txt"};

int main()
{
	node_t* noodle, *point;
	int size, deleted;
	Appointment_t* arr;

	arr = getRequests(&file, &size);
	
	noodle = built_ll(arr,  size, &w_hours);
	
	write_accepted_app(noodle, &file);

	add_personal_data(noodle, &file);
	
	write_accepted_app(noodle, &file);

	deleted = delete_appointments(&noodle, &file);

	free_list(noodle);
	
	return 0;
}
/*____________________________________________________________________*/

/*                  HW10-11 Kevser Yolcu 131044072 
 * 							Test2.c           						  */
/*____________________________________________________________________*/
