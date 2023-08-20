#include "shell.h"

/**
 * builtins_list - checking for match and execute associate builtin
 * @data: structure for the program's data
 * Return: display the return of function executed if there is match,
 * or returns -1.
 **/
int builtins_list(data_of_program *data)
{
	int iterator;
	builtins options[] = {
		{"exit", builtin_exit},
		{"help", builtin_help},
		{"cd", builtin_cd},
		{"alias", builtin_alias},
		{"env", builtin_env},
		{"setenv", builtin_set_env},
		{"unsetenv", builtin_unset_env},
		{NULL, NULL}
	};

/*checking into the structure*/
	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
/*if there is a match between the given command and a builtin,*/
		if (str_compare(options[iterator].builtin, data->command_name, 0))
		{
/*execut function, and return the value of the function*/
			return (options[iterator].function(data));
		}
/*if not match return -1 */
	}
	return (-1);
}
