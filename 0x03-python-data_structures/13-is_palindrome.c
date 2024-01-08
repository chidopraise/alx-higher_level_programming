#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_list - Reverses a linked list
 * @head: Pointer to the head of the list
 * Return: Pointer to the reversed list
 */
listint_t *reverse_list(listint_t **head)
{
	listint_t *prev = NULL, *current = *head, *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
	return (*head);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Pointer to the head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head, *second_half = NULL;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	/* For odd number of nodes, move the slow pointer one step ahead */
	if (fast != NULL)
		slow = slow->next;

	/* Reverse the second half of the list */
	second_half = reverse_list(&slow);

	/* Compare the first and second halves of the list */
	while (*head != NULL && second_half != NULL)
	{
		if ((*head)->n != second_half->n)
			return (0);

		*head = (*head)->next;
		second_half = second_half->next;
	}

	return (1);
}
