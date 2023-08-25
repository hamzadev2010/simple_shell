#include "shell.h"

/**
 * get_input - get input to shell
 *
 * @av: an  arg values
 *
 * Return: line read
 */

char *get_input(char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread =  getline(&line, &len, stdin);
	if (nread == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(0);
		}
		else
		{
			_print(2, av, " :can not read input\n");
			free(line);
			return (NULL);
		}
	}

	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return (line);
}
