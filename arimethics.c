#include "monty.h"

/**
 *add_f - adds the top two elements of the stack
 *@stack: pointer to a pointer to the head of a list
 *@line_number: number of the command in the source file
 *Return: Nothing
 */
void add_f(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL || num_nodes(*stack) < 2)
	{
		free_array(for_free.tokens);
		free(for_free.file_content);
		free_list(*stack);
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	current->next->n = current->n + current->next->n;
	pop_f(stack, line_number);
}

/**
 *sub_f - substracts the top element of the second top element
 *@stack: pointer to a pointer to the head of a list
 *@line_number: number of the command in the source file
 *Return: Nothing
 */
void sub_f(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL || num_nodes(*stack) < 2)
	{
		free_array(for_free.tokens);
		free(for_free.file_content);
		free_list(*stack);
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	current->next->n = current->next->n - current->n;
	pop_f(stack, line_number);
}

/**
 *div_f - divides the second top element of the stack by the top element
 *@stack: pointer to a pointer to the head of a list
 *@line_number: number of the command in the source file
 *Return: Nothing
 */
void div_f(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL || num_nodes(*stack) < 2)
	{
		free_array(for_free.tokens);
		free(for_free.file_content);
		free_list(*stack);
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		free_array(for_free.tokens);
		free(for_free.file_content);
		free_list(*stack);
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	current->next->n = current->next->n / current->n;
	pop_f(stack, line_number);
}

/**
 *mul_f - multiplies the second top element of the stack by the top element
 *@stack: pointer to a pointer to the head of a list
 *@line_number: number of the command in the source file
 *Return: Nothing
 */
void mul_f(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL || num_nodes(*stack) < 2)
	{
		free_array(for_free.tokens);
		free(for_free.file_content);
		free_list(*stack);
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	current->next->n = current->next->n * current->n;
	pop_f(stack, line_number);
}

/**
 *mod_f - computes the rest of the division of the second top element
 *@stack: pointer to a pointer to the head of a list
 *@line_number: number of the command in the source file
 *Return: Nothing
 */
void mod_f(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL || num_nodes(*stack) < 2)
	{
		free_array(for_free.tokens);
		free(for_free.file_content);
		free_list(*stack);
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		free_array(for_free.tokens);
		free(for_free.file_content);
		free_list(*stack);
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	current->next->n = current->next->n % current->n;
	pop_f(stack, line_number);
}
