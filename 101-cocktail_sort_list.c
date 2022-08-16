#include "sort.h"

/**
 * swapper - a function to help swap 2 nodes in a dlist
 * @a: one node
 * @b: the other node
 */
void swap_node(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * cocktail_sort_list - sort list
 * @list: the list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	/* declarations */
	listint_t *my_list;
	int needssort = 1;

	if (!(list && *list))
		return;
	my_list = *list;
	while (needssort)
	{
		needssort = 0;
		while (my_list && my_list->next)
		{
			if (my_list->n > my_list->next->n)
			{
				swap_node(my_list, my_list->next);
				if (my_list->prev->prev == NULL)
					*list = my_list->prev;
				print_list(*list);
				needssort = 1;
			}
			else
				my_list = my_list->next;
		}
		if (!needssort)
			break;
		needssort = 0;
		while (my_list->prev)
		{
			if (my_list->prev->n > my_list->n)
			{
				swap_node(my_list->prev, my_list);
				if (my_list->prev == NULL)
					*list = my_list;
				print_list(*list);
				needssort = 1;
			}
			else
				my_list = my_list->prev;
		}
	}
}
