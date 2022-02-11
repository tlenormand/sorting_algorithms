#include "sort.h"

/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: address of the list to sort
 *
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp = *list, *browse = *list;
	int i, right = 0, left = 0;

	if (!*list || !(*list)->next)
		return;

	while (browse->next != NULL)
		browse = browse->next, right++;

	browse = (*list)->next;
	while (browse && right > left)
	{
		for (i = left; i <= right; i++)
		{
			if (browse && browse->n < tmp->n)
				swap_node(tmp, browse), print_list(*list), browse = browse->next;
			else
				tmp = tmp->next;
			if (browse->next)
				browse = browse->next;
		}
		right--;

		tmp = browse, browse = browse->prev;
		for (i = right; i >= left; i--)
		{
			if (browse->n > tmp->n)
			{
				swap_node(browse, tmp);
				if ((*list)->prev)
					*list = (*list)->prev;
				print_list(*list), browse = browse->prev;
			}
			else
				tmp = tmp->prev;
			if (browse->prev)
				browse = browse->prev;
		}
		left++, tmp = browse, browse = browse->next;
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
