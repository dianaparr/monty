#include "monty.h"


char *_read(const char *filename)/*nombre archivo*/
{
	char *file_content = NULL;
	ssize_t readfile;
	int file_descriptor;

	/*printf("%d\n", prueba);*/
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
	file_content = _calloc(4056, sizeof(char));
	if (file_content == NULL)
		exit(0); /*fallo de memoria*/
	readfile = read(file_descriptor, file_content, 4056);
	if (readfile == -1)
		return (0);
	close(file_descriptor);
	return (file_content);
}