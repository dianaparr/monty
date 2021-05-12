#include "monty.h"

/**
 *create_begining - adds a new node at the beginning of a list
 *@head: pointer to a pointer to the head of a list
 *@data: integer to be added to the list_t list
 *Return: 0 on success
 */
int create_begining(stack_t **head, int data)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
	return (0);
}
