#include "monty.h"

/**
 * main - 
 * @argc: 
 * @argv: 
 *
 * Description:
 */
 int main(int argc, char **argv)
 {
	char *file_content = NULL;
	int len = 0, line_counter = 0;
	char *aux = NULL;
	char **arguments = NULL;


	/* prueba = 15;
	printf("%d\n", prueba); */
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
		while(*(file_content + len) == '\n')
			len += 1;
		aux = _strdup(file_content + len);
		len += strlen(aux) + 1;
		line_counter += 1;
		arguments = split_line(aux); /*tokenizar la linea (aux)*/
		/*enviar al get op function*/

	}
	free(file_content);
	return (0);
}
