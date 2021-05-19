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
		{"nop", nop_f},
		{"pchar", pchar_f},
		{"pstr", pstr_f},
		{"rotl", rotl_f},
		{"rotr", rotr_f},
		{"stack", set_status},
		{"queue", set_status},
		{NULL,  NULL}
	};

	if (for_free.tokens[0][0] == '#')
		return;
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

/**
 *set_status - set a status for stack and queue
 *@line_number: line of the command in the source file
 *@stack: pointeir to the head of a list
 *
 */
void set_status(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (strcmp(for_free.tokens[0], "stack") == 0)
		for_free.status = 0;
	if (strcmp(for_free.tokens[0], "queue") == 0)
		for_free.status = 1;
}