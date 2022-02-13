#ifndef SORT_H
#define SORT_H

/* -------------------------------------------------- */
/* LIBRARIES */

#include <stddef.h>
#include <assert.h>

/* -------------------------------------------------- */
/* STRUCTURES */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* -------------------------------------------------- */
/* GLOBAL VARIABLES */


/* -------------------------------------------------- */
/* PROTOTYPES */

/* functions created before */


/* function created for the exercice */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_node(listint_t *left, listint_t *right);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void a_quick_sort(int *array, int low, int high, size_t size);
int partition(int a[], int low, int high, size_t size);
void swap(int *a, int *b);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void split_merge(int *tmp, int start, int end, int *array);
void merge(int *array, int start, int mid, int end, int *tmp);
void copy_array(int *array, int start, int end, int *tmp);
int len_array(int *array);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t i, size_t size_arr);
void radix_sort(int *array, size_t size);
void swap_array(int *array, size_t left, size_t right);
void bitonic_sort(int *array, size_t size);

#endif /* SORT_H */
