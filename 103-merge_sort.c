#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int *tmp;

	tmp = malloc(sizeof(int) * size);

	if (!array || size < 2)
		return;

	copy_array(array, 0, size, tmp);
	split_merge(tmp, 0, size, array);
}


/**
 * split_merge - recursive function that splid the array in two and
 * then merge the new array sorted
 *
 * @tmp: array to split
 * @start: index to start
 * @end: index to end
 * @array: array to split
 *
 * Return: void
 */

void split_merge(int *tmp, int start, int end, int *array)
{
	int mid;

	if (end - start <= 1)
		return;

	mid = (end + start) / 2;

	split_merge(array, start, mid, tmp);
	split_merge(array, mid, end, tmp);
	merge(tmp, start, mid, end, array);

	printf("[Done]: ");
	print_array(&array[start], end - start);
}


/**
 * merge - function that merge two array together
 * beggining by the smallest index 0
 * copied into the right array
 *
 * @left: left array given
 * @start: index to start
 * @mid: middle of the new array merged
 * @end: index to end
 * @right: right array given
 *
 * Return: void
 */

void merge(int *left, int start, int mid, int end, int *right)
{
	int i = start, j = mid, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(&right[start], mid - start);
	printf("[right]: ");
	print_array(&right[mid], end - mid);

	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || left[i] <= left[j]))
		{
			right[k] = left[i];
			i++;
		}
		else
		{
			right[k] = left[j];
			j++;
		}
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


/**
 * len_array - function that count the length of an array
 *
 * @array: array to count the length
 *
 * Return: length of the array
 */

int len_array(int *array)
{
	int i = 0;

	while (array[i] != '\0')
		i++;

	return (i);
}
