#include "sort.h"

/**
 * insertion_sort_list - sorts an array of integers in ascending order
 * @list: Doubly linked list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL;
	listint_t *tempHead = NULL;
	listint_t *tmp = NULL;

	if (!(*list) || (!((*list)->prev) && !((*list)->next)))
		return;
	head = *list;
	head = head->next;
	while (head)
	{
		tempHead = head->prev;
		if (tempHead->n > head->n)
		{
			swap_nodes(&tempHead, &head, list);
			print_list(*list);
			while (tempHead->prev)
			{
				if ((tempHead->n) < (tempHead->prev->n))
				{
					tmp = tempHead->prev;
					swap_nodes(&tmp, &tempHead, list);
					print_list(*list);
				}
				tempHead = tempHead->prev;
			}
		}
		head = head->next;
	}
}

/**
 * swap_nodes - Swap nodes
 * @one: List 1
 * @two: List 2
 * @list: List
 *
 * Return: Nothing
 */
void swap_nodes(listint_t **one, listint_t **two, listint_t **list)
{
	listint_t *before;
	listint_t *after;

	if (!(*one) || !(*two))
		return;
	before = (*one)->prev;
	after = (*two)->next;

	if (before)
		before->next = (*two);
	(*two)->prev = before;
	(*two)->next = (*one);
	(*one)->prev = (*two);
	(*one)->next = after;

	if (after)
		after->prev = (*one);
	*one = *two;
	*two = (*one)->next;

	if (!before)
		*list = *one;
}
