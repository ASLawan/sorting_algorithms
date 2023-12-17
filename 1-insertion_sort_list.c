#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list
 * using insertion sort algorithm
 * @list: doubly linked list
 * Return: sorted doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr_node, *prev_node, *next_node;

	if (!list || !(*list)->next || !(*list))
		return;
	curr_node = (*list)->next;

	while (curr_node != NULL)
	{
		next_node = curr_node->next;

		while (curr_node->prev != NULL && curr_node->n < curr_node->prev->n)
		{
			prev_node = curr_node->prev;

			if (curr_node->next)
			{
				curr_node->next->prev = prev_node;
			}
			prev_node->next = curr_node->next;
			curr_node->next = prev_node;

			if (prev_node->prev)
			{
				prev_node->prev->next = curr_node;
			}

			curr_node->prev = prev_node->prev;
			prev_node->prev = curr_node;

			if (!curr_node->prev)
			{
				*list = curr_node;
			}

			print_list(*list);
		}
		curr_node = next_node;
	}
}
