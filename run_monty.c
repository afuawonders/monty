#include "monty.h"
#include <string.h>
#define MAX_LINE_LENGTH 1024


void release_tokens_memory(void);
unsigned int get_token_array_length(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t **, unsigned int);
char **op_toks = NULL;

/**
 * release_tokens_memory - Frees the global op_toks array of strings.
 */
void release_tokens_memory(void)
{
size_t i = 0;

if (op_toks == NULL)
return;
for (i = 0; op_toks[i]; i++)
free(op_toks[i]);

free(op_toks);
}

/**
 * get_token_array_length - Gets the length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int get_token_array_length(void)
{
unsigned int toks_len = 0;

while (op_toks[toks_len])
toks_len++;
return (toks_len);
}

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{
int i, j;

for (i = 0; line[i]; i++)
{
for (j = 0; delims[j]; j++)
{
if (line[i] == delims[j])
break;
}
if (delims[j] == '\0')
return (0);
}

return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
instruction_t op_funcs[] = {
{"push", push_to_stack},
{"pall", print_stack},
{"pint", print_top_of_stack},
{"pop", pop_from_stack},
{"swap", swap_stack_top},
{"add", add_stack_top_two},
{"nop", do_nothing},
{"sub", subtract_stack_top_two},
{"div", divide_stack_top_two},
{"mul", multiply_stack_top_two},
{"mod", modulo_stack_top_two},
{"pchar", print_char_from_stack_top},
{"pstr", print_string_from_stack_top},
{"rotl", rotate_left},
{"rotr", rotate_right},
{"stack", set_as_stack},
{"queue", set_as_queue},
{NULL, NULL}};
int i;

for (i = 0; op_funcs[i].opcode; i++)
{
if (strcmp(opcode, op_funcs[i].opcode) == 0)
return (op_funcs[i].f);
}

return (NULL);
}

/**
 * execute_monty_script - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */






/* ... Your other function definitions ... */

/**
 * execute_monty_script - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int execute_monty_script(FILE *script_fd)
{
stack_t *stack = NULL;
char *line = NULL;
/*   size_t len = 0;*/
size_t line_capacity = MAX_LINE_LENGTH;
unsigned int line_number = 0, line_length = 0, prev_tok_len = 0;
int c;
int exit_status;
char *new_line;
void (*op_func)(stack_t **, unsigned int);

if (initialize_stack(&stack) == EXIT_FAILURE)
return (EXIT_FAILURE);

line = (char *)malloc(line_capacity * sizeof(char));
if (line == NULL)
{
fprintf(stderr, "Memory allocation error.\n");
free_stack_and_elements(&stack);
return (EXIT_FAILURE);
}

while ((c = fgetc(script_fd)) != EOF)
{
if (c == '\n')
{
line[line_length] = '\0';
line_length = 0;

line_number++;

op_toks = split_string_by_delimiters(line, DELIMS);
if (op_toks == NULL)
{
if (is_empty_line(line, DELIMS))
continue;
free(line);
free_stack_and_elements(&stack);
return (print_malloc_error_and_exit());
}
else if (op_toks[0][0] == '#') /* comment line */
{
release_tokens_memory();
continue;
}

op_func = get_op_func(op_toks[0]);
if (op_func == NULL)
{
free(line);
free_stack_and_elements(&stack);
exit_status = print_unknown_instruction_error_and_exit(op_toks[0],
line_number);
release_tokens_memory();
return (exit_status);
}

prev_tok_len = get_token_array_length();
op_func(&stack, line_number);
if (get_token_array_length() != prev_tok_len)
{
exit_status = op_toks && op_toks[prev_tok_len] ? atoi
(op_toks[prev_tok_len]) : EXIT_FAILURE;
release_tokens_memory();
free(line);
return (exit_status);
}
release_tokens_memory();
}
else
{

if (line_length >= line_capacity - 1)
{
line_capacity *= 2;
new_line = (char *)realloc(line, line_capacity *sizeof(char));
if (new_line == NULL)
{
fprintf(stderr, "Memory allocation error.\n");
free(line);
free_stack_and_elements(&stack);
return (EXIT_FAILURE);
}
line = new_line;
}

line[line_length] = (char)c;
line_length++;
}
}

free_stack_and_elements(&stack);
free(line);
return (EXIT_SUCCESS);
}
