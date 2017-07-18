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

#define RE "Records"
#define RB "/Records"
#define PA "Patient"
#define PB "/Patient"
#define I "ID"
#define IB "/ID"
#define NM "Name"
#define NB "/Name"
#define HS "History"
#define HB "/History"

#define FILESIZE 90000
#define HISTORYSIZE 500

extern node_t* built_ll(Appointment_t appointments[], int size,
				 const Working_hours_t* hours);

extern int occ(Appointment_t arr[], int arr_size, int hour_of_app);

extern void write_accepted_app(node_t* head, const Files_t* files);

extern void add_personal_data(node_t* head, const Files_t* files);

extern node_t* search_pat_id(node_t* l_list, int p_id);

extern void bingo(node_t* head, char file_str[]);

extern int delete_appointments(node_t** head, const Files_t* files);

extern node_t* search_app_id(node_t* l_list, int a_id);

extern void free_list(node_t* head);

/*____________________________________________________________________*/

/*                  HW10-11 Kevser Yolcu 131044072 
 * 							Part2.h	        						  */
/*____________________________________________________________________*/
