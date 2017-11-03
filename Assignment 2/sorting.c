#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void print(int* array, int length)
{
	for (int i =0; i <length; i++)
	printf("%i ", array[i]);
	
}
void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;

}
int partition(int* array, int first, int last)
{
	int pivot = array[first];
	int i = first;
	int probe = 0;
	for (int j = (first + 1); j <= last; j++)
	{
		if (array[j] <= pivot) 
		{	
			i = i + 1;
			int temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			probe++;

		}
	}

	int tempo = array[i];
	array[i] = array[first];
	array[first] = tempo;

	return i;

}
void bubblesort(int* array, int length)
{
	bool sorted = false;
	int probeb = 0;
	while ( !sorted ) {
		sorted = true;
		for ( int i = 0; i < length - 1; i++ ) {
			if ( array[i + 1] < array[i] ) {
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				probeb++;
				sorted = false;
			}
		}
	}
	printf("Probe Count: %i ", probeb);

}

void quicksort(int* array, int first, int last)
{
	if (first < last)
	{
		int pivot = partition(array, first, last);
		quicksort(array, first, (pivot-1));
		quicksort (array, (pivot+1), last);
	}
	

}



int main()
{
	int array[] = {22,45,35,77,73,52,0,55,77,16};
	//int barray[10];

	//print (array, 8);
//printf("Algorithm Name | Probe Count  |  Big-O Complexity|\n               |              |Best| Average| Worst|\n----------------------------------------------------\n" );
	//bubblesort(array, 4);
	//print(array, 4);
	quicksort(array, 0, 9);
	print(array, 10);
return 0;

}
