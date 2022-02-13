#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, tmp_idx, tmp_val;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		j = i + 1;
		tmp_idx = j;
		while (j < size)
		{
			if (min > array[j])
			{
				min = array[j];
				tmp_idx = j;
			}

			j++;
		}

		if (min != array[i])
		{
			tmp_val = array[tmp_idx];
			array[tmp_idx] = array[i];
			array[i] = tmp_val;
			print_array(array, size);
		}
	}
}
