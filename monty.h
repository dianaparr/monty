#ifndef MONTY_H
#define MONTY_H

/*LIBRARY*/

#include <stdlib.h> /*malloc*/
#include <stdio.h> /*print*/
#include <string.h> /*strtok*/
#include <sys/stat.h> /*Open*/
#include <fcntl.h> /*Open*/
#include <unistd.h> /*Read*/
#include <ctype.h> /*isdigit*/

/* extern int prueba; */

/*STRUCTS*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*PROTOTYPES*/
char *_read(const char *filename);
char *_strdup(char *str);
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **split_line(char *line);
unsigned int counter_words(char *str);
int is_number(char *str);
int create_begining(stack_t **head, int data);
void free_array(char **tokens);
void free_list(stack_t *head);

/*FUNCTIONS PROTOTYPES*/
void get_op_function(char **tokens, unsigned int line_number, stack_t **head);
void pall_f(stack_t **stack, __attribute__((unused))unsigned int line_number);

#endif /* MONTY_H */