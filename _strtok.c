#include "shell.h"

/**
 * _strtok -> constructs full path for an executable function
 *
 * @line: input value
 * @arg: input value
 * Return: int
 */

int _strtok(char *line, char **arg)
{
	int i;
	char *tock;

	for (tock = strtok(line, " \t\n\"\'\\#&*`"), i = 0; tock != NULL;
			tock = strtok(NULL, " \t\n\"\'\\#&*`"), i++)
	{
		arg[i] = tock;
	}
	arg[i] = NULL;
	return (i);
}
