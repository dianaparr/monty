#include "monty.h"

/**
 * free_array - frees a double pointer
 * @tokens: the array to free
 * Return: nothing
 */
void free_array(char **tokens)
{
	int i = 0;

	while (*(tokens + i))
	{
		free(*(tokens + i));
		i++;
	}
	free(tokens);
}

/**
 * free_list - frees a double pointer
 * @head: pointer to the list
 * Return: nothing
 */
void free_list(stack_t *stack)
{
	stack_t *temp = NULL;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
