#include "sort.h"

/**
 * heap_sort - function that sorts an array of integers
 * in ascending order using the Heap sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	size_t size_arr = size;
	size_t i;
	int tmp;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i + 1 > 0; i--)
		heapify(array, size, i, size_arr);

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);

		heapify(array, i, 0, size_arr);
	}
}


/**
 * heapify - function that sorts an array of integers
 * by heap
 *
 * @array: array to sort
 * @size: size of the array
 * @i: index used in recursion
 * @size_arr: total size of the array
 *
 * Return: void
 */

void heapify(int *array, size_t size, size_t i, size_t size_arr)
{
	size_t largest = i;
	size_t l = 2 * i + 1;
	size_t r = 2 * i + 2;
	int swap;

	if (l < size && array[l] > array[largest])
		largest = l;

	if (r < size && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		swap = array[i];
		array[i] = array[largest];
		array[largest] = swap;
		print_array(array, size_arr);

		heapify(array, size, largest, size_arr);
	}
}
