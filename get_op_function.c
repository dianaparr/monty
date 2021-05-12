#include "monty.h"

/**
 *get_op_function - with the command received select the correct function
 *@tokens: are the arguments
 *@line_number: line of the command in the source file
 *@head: pointeir to the head of a list
 *
 *Return: Nothing
 */
void get_op_function(char **tokens, unsigned int line_number, stack_t **head)
{
	int i = 0;
	int data = 0;
	instruction_t options[] = {
		{"pall", pall_f},
		{NULL,  NULL}
	};

	if (strcmp(tokens[0], "push") == 0)
	{
		if (is_number(tokens[1]) != 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		else
		{	data = atoi(tokens[1]);
			create_begining(head, data);
		}
	}
	else
	{
		while (options[i].opcode != NULL)
		{
			if (strcmp(tokens[0], options[i].opcode) == 0)
			{
				options[i].f(head, line_number);
				return;
			}
			i++;
		}
	}
}
