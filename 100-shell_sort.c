#include "sort.h"

/**
 * get_gap - gets the gap size for the sort
 * @size: size of array
 *
 * Return: the gap size
 */
size_t get_gap(size_t size)
{
	/* declarations */
	size_t gap = 1;

	/* looking for gap */
	while (gap < size)
		gap = gap * 3 + 1;
	return ((gap - 1) / 3);
}

/**
 * shell_sort - sort an int array via shell sort
 * @array: the array
 * @size: the size of the array
 *
 */
void shell_sort(int *array, size_t size)
{
	/* declarations */
	size_t gap;
	size_t x;
	size_t y;
	int temp;

	/* check for bad stuff */
	if (!(array && size))
		return;
	/* do the sorting and printing */
	gap = get_gap(size);
	while (gap)
	{
		for (x = gap; x < size; x++)
		{
			temp = array[x];
			for (y = x; y >= gap && array[y - gap] > temp; y -= gap)
			{
				array[y] = array[y - gap];
			}
			array[y] = temp;
		}
		print_array(array, size);
		gap = gap / 3;
	}
}
