#include "monty.h"

/**
 *is_number - returns a pointer to a newly allocated space in memory an copied
 *@str: string to check if is a number
 *
 *Return: 0 if is number and 1 if not
 */
int is_number(char *str)
{
	int len, i;

	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (!isdigit(str[i]))
		{
			return (1); /*is not number*/
		}
	}
	return (0); /*is number*/
}

/**
 *num_nodes - counter of the nodes
 *@head: pointer to the list
 *
 *Return: number of nodes
 */
int num_nodes(stack_t *head)
{
	int counter = 0;
	const stack_t *current = head;

	while (current)
	{
		counter++;
		current = current->next;
	}
	return (counter);
}
