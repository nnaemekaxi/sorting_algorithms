#include "sort.h"

/**
* findmax - Finds the maximum value in an array
* @array: array to find max value of
* @size: Size of array
* Return: Largest value
*/

int findmax(int *array, size_t size)
{
	int i, max = 0;

	for (i = 0; i < (int)size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}

/**
* count - Counts number of occurences of value in an array
* @array: Array to count values of
* @size: Size of array
* @val: Value to count in the array
* Return: Count of va
*/

int count(int *array, size_t size, int val)
{
	int c = 0;
	int x;

	x = 0;
	while (x < (int)size)
	{
		if (array[x] == val)
			c++;
	x++;
	}
	return (c);
}

/**
* counting_sort - sorts array using counting algorithm
* @array: Array to sort
* @size: Size of array
*/

void counting_sort(int *array, size_t size)
{
	int max, *ca, *out;
	int x;
	int j;

	if (array == NULL || size < 2)
		return;
	max = findmax(array, size);
	out = malloc(sizeof(int) * (int)size);
	ca = malloc(sizeof(int) * (max + 1));
	if (ca == NULL || out == NULL)
		return;
	for (x = y = 0; x < max + 1; x++)
	{
		y += count(array, size, x);
		ca[x] = y;
	}
	print_array(ca, max + 1);
	for (x = 0; x < (int)size; x++)
	{
		out[ca[array[x]] - 1] = array[x];
		ca[array[x]] -= 1;
	}
	for (x = 0; x < (int)size; x++)
		array[x] = out[x];

	free(out);
	free(ca);
}
