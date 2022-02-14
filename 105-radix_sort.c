#include "sort.h"

/**
 * radix_sort - function that sorts an array of integers
 * in ascending order using the Radix sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void radix_sort(int *array, size_t size)
{
	int max = 0, j, modulo = 10, divide = 1, unit = 0, idx, idx_swap;
	size_t i, k;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (j = 0; max > 0; j++)
	{
		for (i = 0; i < size - 1; i++)
		{
			unit = (array[i] / divide) % modulo;
			idx = i;
			for (k = i + 1; k < size; k++)
			{
				if (unit > (array[k] / divide) % modulo)
				{
					unit = (array[k] / divide) % modulo;
					idx = k;
				}
			}
			idx_swap = idx - 1;
			while (i < (size_t)idx)
			{
				swap_array(array, idx_swap, idx);
				idx--;
				idx_swap--;
			}
		}
		divide = modulo;
		modulo *= 10;
		max /= divide;
		print_array(array, size);
	}
}


/**
 * swap_array - function that swap two values of an array
 *
 * @array: array to sort
 * @left: left idx of the array
 * @right: right idx of the array
 *
 * Return: void
 */

void swap_array(int *array, size_t left, size_t right)
{
	int tmp;

	if (array && left != right)
	{
		tmp = array[left];
		array[left] = array[right];
		array[right] = tmp;
	}
}


/**
 * copy_array - function that copy an array into another
 *
 * @array: address of the array to copy
 * @start: start index where begging the copy
 * @end: end index where stop the copy
 * @tmp: address of the array to copy into
 *
 * Return: void
 */

void copy_array(int *array, int start, int end, int *tmp)
{
	int k;

	for (k = start; k < end; k++)
		tmp[k] = array[k];
}
