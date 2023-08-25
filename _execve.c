#include "shell.h"

/**
 * run -> forks a child process and running  the specifiy command
 *
 * @arg: input value
 * @commend: input value
 * @str: input value
 * Return: exiting status of fork
 */

int run(char **arg, char *commend, char *str)
{
	int pid = fork();
	int status = 0;
	int f_status = 0;

	if (pid == 0)
	{
		if (execve(commend, arg, NULL) == -1)
		{
			free(commend);
			free(str);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		free(commend);
		if (WIFEXITED(status))
			f_status = WEXITSTATUS(status);
	}
	return (f_status);
}
