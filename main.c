#include "monty.h"

/**
 * main - Entry point
 * @argc: nunber of arguments
 * @argv: arguments from the command line
 *
 * Return: 0 on succes
 */
int main(int argc, char **argv)
{
	char *file_content = NULL;
	int len = 0;
	unsigned int line_counter = 0;
	char *aux = NULL;
	char **tokens = NULL;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_content = _read(argv[1]);
	if (file_content == NULL)
		exit(0);

	while (*(file_content + len))
	{
		while (*(file_content + len) == '\n')
			len += 1;
		aux = _strdup(file_content + len);
		len += strlen(aux) + 1;
		line_counter += 1;
		tokens = split_line(aux); /*tokenizar la linea (aux)*/
		get_op_function(tokens, line_counter, &head);/*enviar al get op function*/
		free_array(tokens);
	}
	free(file_content);
	free_list(head);
	return (0);
}