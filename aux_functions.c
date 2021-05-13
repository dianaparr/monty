#include "monty.h"

/**
 *_strdup - returns a pointer to a newly allocated space in memory an copied
 *@str: the string that we copied
 *
 *Return: a pointer
 */
char *_copy_line(char *str)
{
	int len = 0, i = 0;
	char *dup = NULL;

	if (str == NULL)
		return (NULL);
	/*obtain the lengt of the string*/
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	dup = malloc(sizeof(char) * len + 1);
	if (dup == NULL)
		return (NULL);
	/*duplicate the string in the new pointer*/
	while (str[i] != '\n' && str[len] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}


/**
 * counter_words - counter of words in a string
 * @str: the string
 * Return: a unsigned int number
 */
unsigned int counter_words(char *str)
{
	int state = 0;
	unsigned int counter = 0;
	/*char **array*/
	while (*str != '\0')
	{
		if (*str == 32 || *str == 10 || *str == 9)
		{
			state = 0;
		}
		else if (state == 0)
		{
			state = 1;
			++counter;
		}
		++str;
	}
	return (counter);
}

/**
 *split_line - tokenize the line into an array
 *@line: line with comands to tokenize
 *
 *Return: an array of arrays or NULL if fails
 */
char **split_line(char *line)
{
	unsigned int bufsize, buf_position = 0;
	char **array_tokens = NULL;
	char *single_token = NULL, *delimit = " \t\r\n\a";
	int i = 0, check = 0;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] != ' ' && line[i] != '\n')
			check = 1;
	}
	if (check == 0)
	{
		free(line);
		return (array_tokens);
	}
	bufsize = counter_words(line);
	array_tokens = malloc(bufsize * sizeof(char *) + 1);
	if (!array_tokens)
		return (NULL);
	single_token = strtok(line, delimit);
	while (single_token)
	{
		array_tokens[buf_position] = strdup(single_token);
		buf_position++;
		single_token = strtok(NULL, delimit);
	}
	array_tokens[buf_position] = NULL;
	free(line);
	return (array_tokens);
}

/**
 *_calloc - function that allocates memory for an array
 *@nmemb: number of memory blocks
 *@size: size of each block
 *Return: pointer to mem_arr or NULL (if it fails)
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *mem_arr = NULL;

	if (nmemb == 0 || size == 0)
		return (NULL);
	mem_arr = malloc(nmemb * size);
	if (mem_arr == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
		mem_arr[i] = 0;
	return (mem_arr);
}

/**
 * _realloc - allocates a new memory previous allocated
 * @ptr: the pointer to be new allocated
 * @old_size: the old size of the firs malloc
 * @new_size: the new size to be allocated
 *
 * Return: a new memory allocation
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr = NULL;

	if (old_size == new_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(new_size));
	new_ptr = (void *)malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (new_ptr)
	{
		memcpy(new_ptr, ptr, old_size);
		free(ptr);
	}
	return (new_ptr);
}
