#include "monty.h"


/**
 * set_tokenization_error_code - Sets last
 * element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void set_tokenization_error_code(int error_code)
{
int tokens_lenght = 0, i = 0;
char *exit_str = NULL;
char **new_tokens = NULL;


tokens_lenght = get_token_array_length();
new_tokens = malloc(sizeof(char *) * (tokens_lenght + 2));
if (!op_toks)
{
print_malloc_error_and_exit();
return;
}
while (i < tokens_lenght)
{
new_tokens[i] = op_toks[i];
i++;
}
exit_str = convert_int_to_string(error_code);
if (!exit_str)
{
free(new_tokens);
print_malloc_error_and_exit();
return;
}
new_tokens[i++] = exit_str;
new_tokens[i] = NULL;
free(op_toks);
op_toks = new_tokens;
}
