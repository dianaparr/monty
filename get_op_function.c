#include "monty.h"

/**
 *get_op_function - with the command received select the correct function
 *@for_free.tokens: are the arguments
 *@line_number: line of the command in the source file
 *@head: pointeir to the head of a list
 *
 *Return: Nothing
 */
void get_op_function(unsigned int line_number, stack_t **stack)
{
	int i = 0;
	int data = 0;
	instruction_t options[] = {
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

	if (for_free.tokens == NULL)
		return;
	if (strcmp(for_free.tokens[0], "push") == 0)
	{
		if (for_free.tokens[1] == NULL || is_number(for_free.tokens[1]) != 0)
		{
			free_array(for_free.tokens);
			free_list(*stack);
			free(for_free.file_content);
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		else
		{	data = atoi(for_free.tokens[1]);
			create_begining(stack, data);
		}
	}
	else
	{
		while (options[i].opcode != NULL)
		{
			if (strcmp(for_free.tokens[0], options[i].opcode) == 0)
			{
				options[i].f(stack, line_number);
				return;
			}
			i++;
		}
	}
	/* free(for_free.tokens); */
}
