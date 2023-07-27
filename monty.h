#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"
#define  _POSIX_C_SOURCE 200809L

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

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

/* CORE INTERPRETER FUNCTIONS */
void free_stack_and_elements(stack_t **stack);
int initialize_stack(stack_t **stack);
int evaluate_stack_mode(stack_t *stack);
void release_tokens_memory(void);
unsigned int get_token_array_length(void);
int execute_monty_script(FILE *script_fd);
void set_tokenization_error_code(int error_code);


/* INSTRUCTION IMPLEMENTATION FUNCTIONS */
void push_to_stack(stack_t **stack, unsigned int line_number);
void print_stack(stack_t **stack, unsigned int line_number);
void print_top_of_stack(stack_t **stack, unsigned int line_number);
void pop_from_stack(stack_t **stack, unsigned int line_number);
void swap_stack_top(stack_t **stack, unsigned int line_number);
void add_stack_top_two(stack_t **stack, unsigned int line_number);
void do_nothing(stack_t **stack, unsigned int line_number);
void subtract_stack_top_two(stack_t **stack, unsigned int line_number);
void divide_stack_top_two(stack_t **stack, unsigned int line_number);
void multiply_stack_top_two(stack_t **stack, unsigned int line_number);
void modulo_stack_top_two(stack_t **stack, unsigned int line_number);
void print_char_from_stack_top(stack_t **stack, unsigned int line_number);
void print_string_from_stack_top(stack_t **stack, unsigned int line_number);
void rotate_left(stack_t **stack, unsigned int line_number);
void rotate_right(stack_t **stack, unsigned int line_number);
void set_as_stack(stack_t **stack, unsigned int line_number);
void set_as_queue(stack_t **stack, unsigned int line_number);

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **split_string_by_delimiters(char *str, char *delims);
char *convert_int_to_string(int n);

/* ERROR MESSAGES & ERROR CODES */
int print_usage_and_exit(void);
int print_malloc_error_and_exit(void);
int print_file_open_error_and_exit(char *filename);
int print_unknown_instruction_error_and_exit(char *opcode,
unsigned int line_number);
int print_push_integer_error_and_exit(unsigned int line_number);
int print_pop_error_and_exit(unsigned int line_number);
int print_pint_error_and_exit(unsigned int line_number);
int print_short_stack_error_and_exit(unsigned int line_number, char *op);
int print_divide_by_zero_error_and_exit(unsigned int line_number);
int print_pchar_error_and_exit(unsigned int line_number, char *message);

#endif /* __MONTY_H__ */
