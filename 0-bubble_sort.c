#include "sort.h"

/**
 * bubble_sort - sort an int array with bubble_sort
 * @array: array of integers of size
 * @size: the sze of the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	/* declarations */
	int temp;
	size_t x;
	size_t y;

	/* check for both array & size */
	if (!(array && size))
		return;

	/* let's sort this thing */
	for (x = 0; x < size;)
	{
		for (y = 0; y < size - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
				print_array(array, size);
			}
		}
		x++;
	}
}
