#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	int low = 0;
	int high = (size - 1);

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
 */
void a_quick_sort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		a_quick_sort(array, low, pi - 1, size);
		a_quick_sort(array, pi + 1, high, size);
	}
}

/**
 * partition - Do the partition
 *
 *@a: Array
 *@low: First value of the array
 *@high: Last value of the array
 *@size: Size of the array
 *Return: i
 */
int partition(int a[], int low, int high, size_t size)
{
	int i, j, pivot;

	i = low;
	pivot = a[high];

	for (j = low; j < high; j++)
	{
		if (a[j] < pivot)
		{
			if (i != j)
			{
				swap(&a[i], &a[j]);
				print_array(a, size);
			}
			i++;
		}
	}
	if (a[high] < a[i])
	{
		swap(&a[i], &a[high]);
		print_array(a, size);
	}
	return (i);
}

/**
 * swap - Function that swap both number
 *
 *@a: First number to swap
 *@b: Second number to swap
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
