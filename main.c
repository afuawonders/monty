#include "monty.h"

/**
* main - the entry point for Monty Interp
*
* @argc: the count of arguments passed to the program
* @argv: pointer to an array of char pointers to arguments
*
* Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
*/
int main(int argc, char **argv)
{
FILE *script_fd = NULL;
int exit_code = EXIT_SUCCESS;


if (argc != 2)
return (print_usage_and_exit());
script_fd = fopen(argv[1], "r");
if (script_fd == NULL)
return (print_file_open_error_and_exit(argv[1]));
exit_code = execute_monty_script(script_fd);
fclose(script_fd);
return (exit_code);
}
