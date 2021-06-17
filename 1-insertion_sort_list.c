#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * @list: Double pointer to the head of the linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *aux;

	if (list == NULL || *list == NULL)
		return;
	head = (*list)->next;
	while (head != NULL)
	{
		aux = head->next;
		while (head->prev != NULL && head->prev->n > head->n)
		{
			head->prev->next = head->next;
			if (head->next != NULL)
				head->next->prev = head->prev;
			head->next = head->prev;
			head->prev = head->next->prev;
			head->next->prev = head;
			if (head->prev == NULL)
				*list = head;
			else
				head->prev->next = head;
			print_list(*list);
		}
		head = aux;
	}
}
