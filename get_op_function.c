#include "monty.h"

/**
 *get_op_function - with the command received select the correct function
 *@line_number: line of the command in the source file
 *@stack: pointeir to the head of a list
 *
 *Return: Nothing
 */
void get_op_function(unsigned int line_number, stack_t **stack)
{
	int i = 0;

	instruction_t options[] = {
		{"push", push_f},
		{"pall", pall_f},
		{"pint", pint_f},
		{"pop", pop_f},
		{"swap", swap_f},
		{"add", add_f},
		{"sub", sub_f},
		{"div", div_f},
		{"mul", mul_f},
		{"mod", mod_f},
		{NULL,  NULL}
	};

	while (options[i].opcode != NULL)
	{
		if (strcmp(for_free.tokens[0], options[i].opcode) == 0)
		{
			options[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number,
		for_free.tokens[0]);
	free_all(*stack);
	exit(EXIT_FAILURE);
}
