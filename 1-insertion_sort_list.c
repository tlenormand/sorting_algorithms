#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: address of the list to sort
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *browse;
	listint_t *tmp;

	if (list == NULL || !*list || !(*list)->next)
		return;

	browse = *list;

	while (browse)
	{
		if (browse->prev && browse->prev->n > browse->n)
		{
			tmp = browse;
			while (tmp->prev && tmp->prev->n > tmp->n)
			{
				swap_node(tmp->prev, tmp);
				if ((*list)->prev != NULL)
					*list = (*list)->prev;
				print_list(*list);
			}
		}
		browse = browse->next;
	}
}


/**
 * swap_node - function that swap two nodes in a double linked list
 *
 * @left: address onf the left node
 * @right: address onf the right node
 *
 * Return: void
 */

void swap_node(listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;

	right->next = left;
	left->prev = right;
}
