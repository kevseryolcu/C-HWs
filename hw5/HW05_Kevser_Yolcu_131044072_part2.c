#include<stdio.h>

typedef enum
	{FALSE, TRUE}
bool;

int max_array(int array[], int n);
int min(int a[], int size);
int second_max_array(int array[], int n);
int sum_all_array(const int array[], int n);
int count_array(int array[], int n, int value);
bool search_array(int array[], int n, int value);
void ayirici(char arr[], int size);

int main()
{
	int max;
	int sec_max;
	int sum;
	int count;
	int i;	
	bool s;

	int myarray[] = {6,8,3,3,12,8,3,8,2};

	char arti[20] ;
	for(i=0; i<20 ; ++i)
		arti[i] = '+';

	ayirici(arti, 20);
	max = max_array(myarray, 9);
	printf("Maximum array is %d\n", max);

	
	ayirici(arti, 20);
	sec_max = second_max_array(myarray, 9);
	printf("Second maximum array is %d\n", sec_max);

	ayirici(arti, 20);
	sum = sum_all_array(myarray, 9);
	printf("Sum of all array is %d\n", sum);

	ayirici(arti, 20);
	s = search_array(myarray, 9, 2);



	return 0;

}



/*Returns max value*/
int max_array(int array[], int n)
{
	int i,
		ind,
		temp;
	
	for(i=0; i<(n); ++i)
	{
		ind = min(&array[i], n-i)+i;
		if(i != ind)
		{
			temp = array[i];
			array[i] = array[ind];
			array[ind] = temp;
		}	
	}
	return array[n-1];
}



/*Returns bigger value*/
int min(int a[], int size)
{
	int index=0;
	int i;
	for(i=1; i<size; ++i){
		if(a[i]<a[index])
			index = i;
		}
	return index;
}


/*Returns second max value*/
int second_max_array(int array[], int n)
{
	int s_max;

	s_max = max_array(array, n-2);

	return s_max;
}

/*Returns sum of all array*/
int sum_all_array(const int array[], int n)
{
	int sum = 0;
	int i;
	for(i=0 ; i<n ; ++i)
		sum += array[i];
	return sum;
}


/*Returns count of a value*/
int count_array(int array[], int n, int value)
{


}


/*Prints location of searched value*/
bool search_array(int array[], int n, int value)
{
	int i;
	for(i=0 ; (array[i] != value) && (i < n) ; ++i);
	if(i == n){
		i = -1;
		printf("Value is not found\n");
		return FALSE;
	}

	else
	{
		printf("%d is at %d\n", value, i);
		return TRUE;
	}
	
}


void ayirici(char arr[], int size)
{
	int i;
	for(i=0; i<size; ++i)
		printf("%c", arr[i]);
	
	printf("\n");
}
