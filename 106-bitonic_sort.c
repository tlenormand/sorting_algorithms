#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void merge_up(int *array, size_t size)
{
	int gap = size / 2, i, j, k, tmp;

	while (gap > 0)
	{
		for (i = 0; i < (int)size; i += gap * 2)
		{
			for (j = i, k = 0; k < gap; j++, k++)
			{
				if (array[j] > array[j + gap])
				{
					tmp = array[j];
					array[j] = array[j + gap];
					array[j + gap] = tmp;
				}
			}
		}
		gap /= 2;
	}
	print_array(array, size);
}

void merge_down(int *array, int size)
{
	int gap = size / 2, i, j, k, tmp;

	while (gap > 0)
	{
		for (i = 0; i < size; i += gap * 2)
		{
			for (j = i, k = 0; k < gap; j++, k++)
			{
				if (array[j] < array[j + gap])
				{
					tmp = array[j];
					array[j] = array[j + gap];
					array[j + gap] = tmp;
				}
			}
		}
		gap /= 2;
	}
	print_array(array, size);
}

void bitonic_sort(int *array, size_t size)
{
	size_t i, s, iteration = 1;

	for (s = 2; s <= size; s *= 2)
	{
		for (i = 0; i < size; i += s * 2)
		{
			printf("Merging [%ld/%ld] (UP):\n",size / iteration, size);
			print_array((array + i), s);
			printf("Result [%ld/%ld] (UP):\n",size / iteration, size);
			merge_up((array + i), (int)s);
			printf("Result [%ld/%ld] (DOWN):\n",size / iteration, size);
			merge_down((array + i + s), (int)s);
			iteration *= 2;
		}
	}

	print_array(array, size);
}
