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

/**
 *pint_f - prints the value at the top of the stack
 *@stack: pointer to a pointer to the head of a list
 *@line_number: number of the command in the source file
 *Return: Nothing
 */
void pint_f(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}

/**
 *pop_f - remueves the top element of the stack
 *@stack: pointer to a pointer to the head of a list
 *@line_number: number of the command in the source file
 *Return: Nothing
 */
void pop_f(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->next)
		current->next->prev = NULL;
	*stack = current->next;
	current->next = NULL;
	free(current);
}

/**
 *swap_f - swaps the top two elements of the stack
 *@stack: pointer to a pointer to the head of a list
 *@line_number: number of the command in the source file
 *Return: Nothing
 */
void swap_f(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL || num_nodes(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		current->next->prev = current->prev;
		current->prev = current->next;
		current->next = current->next->next;
		current->prev->next = current;
		*stack = current->prev;
		if (current->next != NULL)
			current->next->prev = current;
	}
}
