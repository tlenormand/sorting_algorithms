#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers
 * in ascending order using the Shell sort algorithm
 * using the Knuth sequence (n+1 = n * 3 + 1)
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, tmp_idx, tmp_val, gap = 1;
	int min;

	if (!array || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap)
	{
		for (i = 0; i < gap; i++)
		{
			for (j = i; j + gap < size; j += gap)
			{
				min = array[j];
				tmp_idx = j;
				while (tmp_idx < size)
				{
					if (array[tmp_idx] < min)
						min = array[tmp_idx], tmp_val = tmp_idx;
					tmp_idx += gap;
				}

				if (array[j] > min)
				{
					array[tmp_val] = array[j];
					array[j] = min;
				}
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
