#include "sort.h"

/**
* selection_sort - a function that sorts an array of integers in ascending
* order using the selection sort algorithm
* @array: array of integers
* @size: size of array
**/

void selection_sort(int *array, size_t size)
{
	size_t x;
	size_t y;
	int *temp;

	temp = NULL;
	for (y = 0; array && y < size - 1; y++)
	{
		temp = NULL;
		for (x = y + 1; x < size; x++)
		{
			if (array[x] < array[y])
			{
				if (temp && array[x] < *temp)
					temp = &array[x];
				if (!temp)
					temp = &array[x];
			}
		}
		if (temp)
		{
			swap_integers(temp, &array[y]);
			print_array(array, size);
		}
	}
}
/**
* swap_integers - swaps the values of two integers
* @a: take an int
* @b: take an int
**/
void swap_integers(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
