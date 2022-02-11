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
	int *left, *right;
	size_t i;
	
	if (!array || size < 2)
		return;
	
	left = malloc(sizeof(int) * size / 2 + 1);
	right = malloc(sizeof(int) * size / 2 + 1);

	if (!left && !right)
		return;

	for (i = 0; i < size / 2; i++)
		left[i] = array[i];

	for (i = size / 2; i < size; i++)
		right[i - size / 2] = array[i];

	fusion(merge_sort(left, size / 2), merge_sort(right, size / 2), size / 2);
}

void fusion(int *array, int *left, int *right, size_t size)
{
	size_t len_left, len_right, i, j;
	
	if (!left || !right)
		return;

	for (i = 0; i < size - 1; i++)
		len_left++;

	len_right = len_left;

	if (left[0] < right[0])
	{
		for (i = 0; i < len_left - 1; i++)
			array[i] = left[i];
		for (j = 0; j < len_right - 1; j++)
		{
			array[i] = right[j];
			i++;
		}
	}
	else if (right[0] < left[0])
	{
		for (i = 0; i < len_right - 1; i++)
			array[i] = right[i];
		for (j = 0; j < len_left - 1; j++)
		{
			array[i] = left[j];
			i++;
		}
	}
}