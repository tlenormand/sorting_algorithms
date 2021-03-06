#include "sort.h"
#include <stdio.h>

/**
 * quick_sort_hoare - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void quick_sort_hoare(int *array, size_t size)
{
	int low = 0;
	int high = size - 1;

	if (!array || size < 2)
		return;

	a_quick_sort(array, low, high, size);
}


/**
 * a_quick_sort - Main function to launch the algo
 *
 *@array: Array to sort
 *@low: First value of the array
 *@high: Last value of the array
 *@size: Size of the array
 *
 * Return: void
 */

void a_quick_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		a_quick_sort(array, low, pivot, size);
		a_quick_sort(array, pivot + 1, high, size);
	}
}


/**
 * partition - Do the partition
 *
 *@array: Array
 *@low: First value of the array
 *@high: Last value of the array
 *@size: Size of the array
 *
 *Return: i
 */

int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot;

	pivot = array[high];
	i = low;
	j = high;

	while (1)
	{
		while (array[i] < pivot)
			i++;

		while (array[j] > pivot)
			j--;

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
			i++;
			j--;
		}
		else
		{
			if (i != j)
				return (j);
			return (j - 1);
		}
	}
}


/**
 * swap - Function that swap both number
 *
 *@left: First number to swap
 *@right: Second number to swap
 *
 * Return: void
 */

void swap(int *left, int *right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}
