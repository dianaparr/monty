#include "monty.h"

/**
 *nop_f - doesn't do anything
 *@stack: pointer to a pointer to the head of a list
 *@line_number: number of the command in the source file
 *Return: Nothing
 */
void nop_f(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 *pchar_f - print ascii code
 *@stack: pointer to a pointer to the head of a list
 *@line_number: number of the command in the source file
 *Return: Nothing
 */
void pchar_f(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		free_all(*stack);
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->n >= 32 && current->n <= 126)
		printf("%c\n", current->n);
	else
	{
		free_all(*stack);
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 *pstr_f - print string in ascii code
 *@stack: pointer to a pointer to the head of a list
 *@line_number: number of the command in the source file
 *Return: Nothing
 */
void pstr_f(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current = *stack;

	if (num_nodes(*stack) != 0)
	{
		while (current != NULL || current->n != 0)
		{
			if (current->n > 32 && current->n <= 126)
				printf("%c", current->n);
			else
				break;
			current = current->next;
		}
	}
	printf("\n");
}
