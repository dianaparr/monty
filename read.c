#include "monty.h"

/**
 * _read - open a file and keep it in a buffer
 * @filename: name of the file to open
 * Return: pinter of the buffer
 */
char *_read(const char *filename)/*nombre archivo*/
{
	char *file_content = NULL;
	ssize_t readfile;
	int file_descriptor;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	file_content = _calloc(31966, sizeof(char));
	if (file_content == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	readfile = read(file_descriptor, file_content, 31966);
	if (readfile == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	file_content[readfile] = '\0';
	close(file_descriptor);
	return (file_content);
}
