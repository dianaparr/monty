#include "monty.h"

/**
 *pall_f - prints all the values on the stack
 *@stack: pointer to a pointer to the head of a list
 *@line_number: number of the command in the source file
 *Return: Nothing
 */
void pall_f(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
