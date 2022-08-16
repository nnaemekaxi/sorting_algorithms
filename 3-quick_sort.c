#include "sort.h"

/**
 * swaps_integers - swaps and prints ints from an array without temp
 * @array: the array for printing func
 * @size: the size of array for printing func
 * @a: one int
 * @b: the other int
 */
void swaps_integers(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}
/**
 * quicksort - quick sort via lamuto partition
 * @array: the array
 * @size: size of array
 * @low: low [] of sort
 * @high: high [] of sort
 *
 */
void quicksort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t part = partition(array, size, low, high);

		quicksort(array, size, low, part - 1);
		quicksort(array, size, part + 1, high);
	}
}

/**
 * quick_sort - to quick sort, basically a junk func prototype i had to
 * embetter
 * @array: the array to sort
 * @size: size of array
 *
 */
void quick_sort(int *array, size_t size)
{
	/* if bad things, return */
	if (!array || !size)
		return;
	/* else, sort it baby */
	quicksort(array, size, 0, size - 1);
}

/**
 * partition_array - function partitions array
 * @array: the array
 * @size: the size of array
 * @low: the bottom of the index
 * @high: the top of it
 * Return: size_t part, the partition value
 */
size_t partition_array(int *array, size_t size, ssize_t low, ssize_t high)
{
	/*declarations */
	int x;
	int y; 
	int z;

	/* set the pivot */
	z = array[high];

	for (y = low, x = y; y < high; y++)
	{
		if (array[y] < z)
		{
			swaps_integers(array, size, &array[y], &array[x++]);
		}
	}
	/* final swap */
	swaps_integers(array, size, &array[x], &array[high]);
	/* the size_t return value here is needed for the part */
	return (x);
}
