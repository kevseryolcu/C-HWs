/*************************************************************
 *                                                           *
 * HW04 Q3                                                   *
 * Student Name: Kevser Yolcu                                *
 * Student ID  : 131044072                                   *
 * Date        : 16.03.2015                                  *
 * Points      : 46                                          *
 *                                                           *
 *************************************************************/
#include <stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define CHARACTERFILE "Files/Q3/CharacterList.txt"
#define SAMPLEFILE "Files/Q3/Sample.txt"
#define ENCODEDFILE "Files/Q3/XUniversityEncoded.txt"
#define PLAINTEXTFILE "Files/Q3/XUniversityMessage.txt"



/*************************************************************
 * Read characters from character list file and if character *
 * is letter assign characters to c1, c2 and c3.             *
 * If file has not three letters assign NULL to input char   *
 * by order. For ex. file has two letters assign proper      *
 * letters to c1 and c2 and assign NULL to c3. If file has   *
 * four letters assign c1, c2 and c3 first three letters.    *
 * Return number of letters in character list file.          *
 * Do not forget to count only proper letters with your      *
 * is_letter function. Return number of letters not chars    *
 *************************************************************/
int 
read_character_list(FILE* f_in_ptr, char *c1, char *c2, char *c3);



/*************************************************************
 * Check whether character is big ASCII letter or not        *
 * return TRUE or FALSE                                      *
 *************************************************************/
int 
is_letter(char c);



/*************************************************************
 * Read letters from Sample file and compute frequency of    *
 * letters. Then sort it inside this function. Call sort     *
 * function. At the end make sure that *c1 keeps most        *
 * frequent used letter, *c3 keeps least frequent used       *
 * letter and *c2 keeps remained letter                      *
 *************************************************************/
void 
count_letters(FILE *f_in_ptr, char *c1, char *c2, char *c3);



/*************************************************************
 * Sorts characters according to counts. At the end          *
 * make sure that *c1 keeps most frequent used letter, *c3   *
 * keeps least frequent used letter and *c2 keeps remained   *
 * letter                                                    *
 *************************************************************/
void
sort(char *a, int a_num, char *b, int b_num, char *c, int c_num);



/*************************************************************
 * Swaps values of two integers                              *
 *************************************************************/
void 
swap_int(int *a, int *b);



/*************************************************************
 * Swaps values of two characters                            *
 *************************************************************/
void 
swap_char(char *a, char *b);



/*************************************************************
 * Read from XUniversityEncoded file to decode message and   *
 * write decoded (plain text) message to XUniversityMessage  *
 * file. Make sure c1 keeps most frequent used letter,  c3   *
 * keeps least frequent used letter and  c2 keeps remained   *
 * letter while calling function. According to frequency     *
 * you know their codes. c1: 0, c2: 10, c3: 110.             *
 *************************************************************/
void 
decode(FILE *f_in_ptr, FILE *f_out_ptr, char c1, char c2, char c3);



/*************************************************************
 * Learns XUniversity's encoding system from given files ,   *
 * decodes their encoded messages and writes as plain text to*
 * a file                                                    *
 *************************************************************/
int 
main(int argc, char* argv[])
{
	FILE *f_character_list_ptr,
	     *f_sample_file_ptr, 
		 *f_encoded_ptr,
		 *f_plain_text_ptr;
		 
	int character_number;
	char c1, c2, c3;
	
	/* exit program and print error if character list file could not be opened to read */
	f_character_list_ptr = fopen( CHARACTERFILE , "r");
	f_sample_file_ptr    = fopen( SAMPLEFILE , "r");
	f_encoded_ptr 	     = fopen( ENCODEDFILE , "r");
	f_plain_text_ptr     = fopen( PLAINTEXTFILE , "w");
	
	
	
	
	if(f_character_list_ptr == (NULL)){
			printf("Character List File could not be opened to read!!");
			exit (0);
		}
		
	/* call read_character_list function and get return value *
	
	 * if number of letter read is not equal to three exit    *
	 * program                                                */
	
	character_number = read_character_list(f_character_list_ptr, &c1, &c2, &c3);
	
	if(character_number > 3 || character_number <1)
		exit (0);
		
	/* close character list file */
	fclose(f_character_list_ptr);




	/* exit program and print error if sample file could not be opened to read */
	if(f_sample_file_ptr == (NULL)){
				printf("Sample File could not be opened to write!!");
				exit (0);
			}

	/* Call count_letters function and swap letters inside function *
	 * according to number of counts                                */	
	
	count_letters(f_sample_file_ptr, &c1, &c2, &c3);
	
	/* close sample file */
	fclose(f_sample_file_ptr);
 
 
 
 
	/* exit program and print error if encoded file could not be opened to read */
	
	/* exit program and print error if plain text file could not be opened to write */
	
	if(f_encoded_ptr == (NULL)){
			printf("XUniversity Encoded File could not be opened to read!!");
			exit (0);
		}
	if(f_plain_text_ptr == (NULL)){
			printf("XUniversity Message File could not be opened to write!!");
			exit (0);
		}	
	
	/* Call decode function */	

	decode(f_encoded_ptr, f_plain_text_ptr, c1, c2, c3);


	/* close encoded and plain text file */

	fclose(f_encoded_ptr);
	fclose(f_plain_text_ptr);

	return 0;
}




/*************************************************************
 * Read characters from character list file and if character *
 * is letter assign characters to c1, c2 and c3.             *
 * If file has not three letters assign NULL to input char   *
 * by order. For ex. file has two letters assign proper      *
 * letters to c1 and c2 and assign NULL to c3. If file has   *
 * four letters assign c1, c2 and c3 first three letters.    *
 * Return number of letters in character list file.          *
 * Do not forget to count only proper letters with your      *
 * is_letter function. Return number of letters not chars    *
 *************************************************************/
int 
read_character_list(FILE* f_in_ptr, char *c1, char *c2, char *c3)
{	
	int counter = 0;
	int status = 0;
	int torf;
	char karakter;
	
	do{
		status = fscanf(f_in_ptr, "%c", &karakter);  
		
		torf = is_letter(karakter);
		
		if(torf == TRUE){
			counter += 1;
			
			if(counter == 1)
				*c1 = karakter;
			else if(counter == 2)
				*c2 = karakter;
			else if(counter == 3)
				*c3 = karakter;
		}
		 
	}while(status != EOF);
		
	return counter;
}




/*************************************************************
 * Check whether character is big ASCII letter or not        *
 * return TRUE or FALSE                                      *
 *************************************************************/
int 
is_letter(char c)
{
	if(c >= 65 && c <= 90)
		return TRUE;
	
	else
		return FALSE;

}




/*************************************************************
 * Read letters from Sample file and compute frequency of    *
 * letters. Then sort it inside this function. Call sort     *
 * function. At the end make sure that *c1 keeps most        *
 * frequent used letter, *c3 keeps least frequent used       *
 * letter and *c2 keeps remained letter                      *
 *************************************************************/
void 
count_letters(FILE *f_in_ptr, char *c1, char *c2, char *c3)
{
	char temp;
	int status = 0,
	    count1 = 0,
	    count2 = 0,
	    count3 = 0;

	 do{	 
		status = fscanf(f_in_ptr, "%c" , &temp );
	
		if(temp == *c1)
			count1 += 1;
			
		else if(temp == *c2)
			count2 += 1;
			
		else if(temp == *c3)
			count3 += 1;
		else
			exit (0);
		
	 }while(status != EOF);
	 
	 sort(c1, count1, c2, count2, c3,  count3);

}




/*************************************************************
 * Sorts characters according to counts. At the end          *
 * make sure that *c1 keeps most frequent used letter, *c3   *
 * keeps least frequent used letter and *c2 keeps remained   *
 * letter                                                    *
 *************************************************************/
void
sort(char *a, int a_num, char *b, int b_num, char *c, int c_num)
{
	
	if(a_num > b_num && b_num > c_num){
	}
				
	else if(a_num < b_num && b_num < c_num){
		swap_char(a , c);
		swap_int(&a_num , &c_num);
	}	
	
	else if(a_num < b_num && c_num < a_num){
		swap_char(a , b);
		swap_int(&a_num , &b_num);
	}

	else if(c_num < a_num && b_num < c_num){
		swap_char(c , b);
		swap_int(&c_num , &b_num);
	}

	else if(a_num < c_num && b_num < a_num){
		swap_char(a , c);
		swap_int(&a_num , &c_num);
		
		swap_char(b , c);
		swap_int(&b_num , &c_num);
	}
	
	else if(c_num < b_num && a_num < c_num){
		swap_char(a , b);
		swap_int(&a_num , &b_num);
		
		swap_char(b , c);
		swap_int(&b_num , &c_num);
	}

	else
		exit(0);

}




/*************************************************************
 * Swaps values of two integers                              *
 *************************************************************/
void 
swap_int(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
	
}




/*************************************************************
 * Swaps values of two characters                            *
 *************************************************************/
void 
swap_char(char *a, char *b)
{
	char chtemp;
	
	chtemp = *a;
	*a = *b;
	*b = chtemp;	
}




/*************************************************************
 * Read from XUniversityEncoded file to decode message and   *
 * write decoded (plain text) message to XUniversityMessage  *
 * file. Make sure c1 keeps most frequent used letter,  c3   *
 * keeps least frequent used letter and  c2 keeps remained   *
 * letter while calling function. According to frequency     *
 * you know their codes. c1: 0, c2: 10, c3: 110.             *
 *************************************************************/
void 
decode(FILE *f_in_ptr, FILE *f_out_ptr, char c1, char c2, char c3){
	char karakter;
	int status = 0;
	int count = 0;

	 do{
		

		do{
			status = fscanf(f_in_ptr, "%c" , &karakter );
	
			count += 1;

		}while(karakter != '0');
		
		if(status == EOF)
			break;
		
		if(count == 1)
			fprintf(f_out_ptr, "%c", c1);
		else if(count == 2)
			fprintf(f_out_ptr, "%c", c2);
		else if(count == 3)
			fprintf(f_out_ptr, "%c", c3);
		else
			printf("XUniversityEncoded.txt includes undeclerated character");

		count = 0;

	}while(status != EOF);

}

