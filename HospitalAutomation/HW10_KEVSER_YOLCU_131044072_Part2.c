/*____________________________________________________________________*/

/*                  HW10-11 Kevser Yolcu 131044072 
 * 							Part2.c           						  */
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

/* 	considers all appointments in the array, builds and returns a 
 * linked­list including all appointment requests in the order of their 
 * time,  except:
	◦ those for out of working hours
	◦ those for an already reserved time (2nd and other requests for the same time)
	An empty string should be assigned to name field and a NULL pointer to history field of 
	each record.*/
node_t* built_ll(Appointment_t appointments[], int size,
				 const Working_hours_t* hours)
{
	node_t* l_list = NULL, *new;
	int i; 
	for(i = 0; i<size; ++i)
	{
		if(appointments[i].hour >= hours->start && appointments[i].hour < hours->end)
		{
			if(occ(appointments, size, appointments[i].hour) == 0)
			{
				new = malloc(sizeof(node_t));
				new->app_id = appointments[i].app_id;
				new->patient_id = appointments[i].patient_id;
				new->hour = appointments[i].hour;
				new->name[0] = '\0';
				new->history = (NULL);
				new->next = l_list;
				l_list = new;			
			}
		}
	}
	
	return l_list;
}

int occ(Appointment_t arr[], int arr_size, int hour_of_app)
{
	int count = 0, i;

	for(i = 0; i<arr_size; ++i)
		if(arr[i].hour == hour_of_app)
			count += 1; 	
			
	if(count == 1)
		count = 0;
	
	return count;
	
}


/*write all appointments in the list into the accepted appointment file 
 * in the described format. Note that this function should work properly 
 * both before and after assigning the name and the history fields of 
 * appointments.
*/
void write_accepted_app(node_t* head, const Files_t* files)
{
	FILE* inp;
	node_t* temp;
	int no = 1;
	
	temp = head;
	
	inp = fopen(files->accepted_appo_file_n, "w");
	
	fprintf(inp, "no;id;patient_id;name;history;hour\n");
	
	do{
		if(temp->name[0] == '\0' || temp->history == (NULL))
		{
			if(temp->name[0] == '\0' && temp->history == (NULL)){
				fprintf(inp, "%d;%d;%d;;;%d\n", no, temp->app_id,
						temp->patient_id, temp->hour);
			}
			else if(temp->name[0] == '\0' && temp->history != (NULL)){
				fprintf(inp, "%d;%d;%d;;%s;%d\n", no, temp->app_id,
						temp->patient_id, temp->history, temp->hour);
			}
			else{
				fprintf(inp, "%d;%d;%d;%s;;%d\n", no, temp->app_id,
						temp->patient_id, temp->name, temp->hour);
			}
				
		}
		
		else{
			fprintf(inp, "%d;%d;%d;%s;%s;%d\n", no, temp->app_id,
			   temp->patient_id, temp->name, temp->history, temp->hour);
		}
		
		temp = temp->next;
		
		no += 1;
		
	}while(temp != NULL);

	fclose(inp);
}


/*takes personal data from the patients file and adds the corresponding 
 * name and history information to each appointment. Note that the name 
 * field has its allocated storage while the history field does not have.
 *  So, atfirst, required amount of dynamic allocation should be 
 * assigned to history field.  
*/
void add_personal_data(node_t* head, const Files_t* files)
{
	FILE* inp;
	int status = 0, i = 0;
	char all_str[FILESIZE];
	
	inp = fopen(files->patients_file_n, "r");
	
	while(status != EOF)
	{
		status = fscanf(inp, "%c", &all_str[i]);		
		if(all_str[i] == '\n')
			i -= 1;
		i += 1;	
	}

	bingo(head, all_str);
		
	fclose(inp);
}
/*Takes to pieces the string, datas in the string matchs the linked list */
void bingo(node_t* head, char file_str[])
{
	node_t* x;
	char* token;
	int id;
	char temp[1];
	int deb = 0;

	token = malloc(sizeof(char)*HISTORYSIZE);
	
	token = strtok(file_str, "<>	");
		
	do{
		if(!strcmp(token, PA))
		{				
			token = strtok(NULL , "<>	");
				
			if(strcmp( token , I) == 0 )
			{		
				token = strtok(NULL, "<>	");		
				id = atoi(token);
				x = search_pat_id(head, id);
					
				if(x != NULL)
				{
					while( (strcmp(( token=strtok(NULL,"<>	") ),NM)!=0 && 
						    strcmp(token,HS) != 0) && strcmp(token,PB)!= 0 );
						
					if(strcmp( token , HS) == 0 )
					{
						token = strtok(NULL, "<>	");
						
						if(strcmp(token, HB) != 0 )
							strcpy(x->history, token); 					
					}
						
					else if(strcmp( token , NM) == 0 )
					{
						token = strtok(NULL, "<>	") ;
						
						if( strcmp(token, NB) != 0)
							strcpy(x->name , token);
							
						token = strtok(NULL, "<>	");
						
						if(strcmp( (token = strtok(NULL,"<>	")),HS )==0)
						{
							token = strtok(NULL, "<>	");
							
							if(strcmp(token, HB) != 0 )
								x->history = token;
					
						}				
					}
				}			
			}	
		}		
	}while( (token = strtok(NULL, "<>	") ) != NULL);
		
}

/*Searchs patient_id takes from file in linked list and returns address 
 * of patients_id if it finds*/
node_t* search_pat_id(node_t* l_list, int p_id)
{
	node_t* xp;
	xp = l_list;
	
	while(xp != NULL && xp->patient_id != p_id)
		xp = xp->next;
		
	return xp;
}

/*deletes all records in the delete file from the linked list and 
 * returns the number of appointments deleted.
*/
int delete_appointments(node_t** head, const Files_t* files)
{
	FILE* inp;
	
	int k,
	    deleted = 0,
	    status  = 0;
	    
	node_t* list, *src;
	
	list = *head;
	
	inp = fopen(files->delete_file_n, "r");
		
	do{
		status = fscanf(inp, "%d", &k);

		src = search_app_id(list, k);
	
		if(src != NULL)
			deleted += 1;
	
	}while(status != EOF);

	return deleted;

}
/*Searchs app_id takes from file in linked list and if function finds it
 *  deletes it*/
node_t* search_app_id(node_t* l_list, int a_id)
{
	node_t* yp, *prev, *temp;
	yp = l_list;
	
	while(yp != NULL && yp->app_id != a_id)
	{
		prev = yp;
		yp = yp->next;
	}	
	
	if(yp != NULL){
		if(yp->app_id == a_id)
		{
			temp = yp;
			yp = yp->next;
			free(temp);
		}
	}
	
	return yp;
}

/*frees all dynamically allocated memory in the list. Should be 
 * able to work properly both before and after assigning the name and 
* the history fields of appointments.
*/
void free_list(node_t* head)
{
	node_t*  m;
	
	while(head != NULL)
	{
		m = head;
		head = head->next;
		free(head);
	}	
	if(head == NULL)
		free(head);
	
}
/*____________________________________________________________________*/

/*                  HW10-11 Kevser Yolcu 131044072 
 * 							Part2.c           						  */
/*____________________________________________________________________*/

