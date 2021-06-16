#include "sort.h"

/**
 * swap - swaps a node's position.
 * @current: is the current node.
 * @list: is the pointer to the head of the node list.
 * Return: returns a pointer to the exchanged node.
 */
listint_t *swap_node(listint_t *current, listint_t **list)
{
	listint_t *before, *next, *after;

	if (current && current->prev &&
		current->next && current->next->next)
	{
		before = current->prev;
		next = current->next;
		after = current->next->next;

		before->next = next;
		current->prev = next;
		current->next = after;
		next->next = current;
		after->prev = current;
		next->prev = before;
		print_list(*list);
	}
	else
	{
		before = current->prev;
		next = current->next;

		before->next = next;
		current->prev = next;
		next->prev = before;
		next->next = current;
		current->next = NULL;
		print_list(*list);
	}
	return (next);
}
/**
 * swap_reverse - swaps a node's position.
 * @current: is the current node.
 * @list: is the pointer to the head of the node list.
 * Return: returns a pointer to the exchanged node.
 */
listint_t *swap_reverse(listint_t *current, listint_t **list)
{
	listint_t *before, *next, *prev;

	if (current && current->next && current->prev &&
		current->prev->prev)
	{
		next = current->next;
		prev = current->prev;
		before = current->prev->prev;

		current->next = prev;
		prev->next = next;
		next->prev = prev;
		current->prev = before;
		before->next = current;
		prev->prev = current;
		print_list(*list);
	}
	else
	{
		next = current->next;
		*list = current;
		before = current->prev;

		current->prev = NULL;
		current->next = before;
		before->prev = current;
		before->next = next;
		next->prev = before;
		print_list(*list);

		return (before);
	}
	return (prev);
}
/**
 * insertion_sort_list - sorts an array of integers
 *			in ascending order using the Bubble sort
 *			algorithm
 * @list: is the pointer to the head of the node list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list, *aux;

	if (list == NULL)
	{
		return;
	}

	while (head->next != NULL)
	{
		if (head->n > head->next->n)
		{
			head = swap_node(head, list);
			aux = head;

			while (aux->prev != NULL)
			{
				if (aux->n < aux->prev->n)
				{
					aux = swap_reverse(aux, list);
				}
				aux = aux->prev;
			}
		}
		head = head->next;
	}
}
