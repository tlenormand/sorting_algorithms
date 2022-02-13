#include "sort.h"
#include <stdio.h>

/**
 * radix_sort - function that sorts an array of integers
 * in ascending order using the Radix sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void bitonic_sort(int *array, size_t size)
{


	if (!array || size < 2)
		return;
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
