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
		free_all(*head);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	new_node->next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	new_node->prev = NULL;
	*head = new_node;

	return (0);
}
/**
 * create_end - adds a new node at the end of a list.
 * @head: pointer of the header of the list
 * @data: data to put in the new node
 * Return: the address of the new element, or NULL if it failed
 */
int create_end(stack_t **head, int data)
{
	stack_t *current = *head;
	stack_t *new_node = NULL;

	if (!head)
		return (0);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		free_all(*head);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->n = data;
	if (*head == NULL)
	{
		*head = new_node;
		return (0);
	}
	else
	{
		while (current)
		{
			if (!current->next)
			{
				new_node->prev = current;
				current->next = new_node;
				return (0);
			}
			current = current->next;
		}
	}
	return (0);
}
