#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	size_t j;
	int *new;
	int max = 0, find = 0, count = 0, i, idx = 0;

	if (!array || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
		if (array[j] > max)
			max = array[j];

	new = malloc(sizeof(int) * max + 1);

	for (i = 0; i < max + 1; i++)
	{
		for (j = 0; j < size; j++)
			if (i == array[j])
				find++;

		new[i] = find;
	}
	print_array(new, max + 1);

	for (i = 0; i < max + 1; i++)
	{
		if (i != 0 && new[i] != new[i - 1])
		{
			array[idx] = count;
			idx++;
		}

		count++;
	}

	free(new);
}
