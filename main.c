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
	int len = 0;
	unsigned int line_counter = 0;
	char *aux = NULL;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	for_free.file_content = _read(argv[1]);
	if (for_free.file_content == NULL)
		exit(0);

	while (*(for_free.file_content + len))
	{
		while (*(for_free.file_content + len) == '\n')
			len += 1;
		aux = _copy_line(for_free.file_content + len);
		len += strlen(aux) + 1;
		line_counter += 1;
		for_free.tokens = split_line(aux); /*tokenizar la linea (aux)*/ /*tokes*/
		if (for_free.tokens != NULL)
		{
			get_op_function(line_counter, &head);/*enviar al get op function*/
			free_array(for_free.tokens);
		}
	}
	free(for_free.file_content); /*Para estructura nueva*/
	free_list(head);
	return (0);
}
