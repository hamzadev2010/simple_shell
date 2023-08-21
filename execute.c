#include "shell.h"
/**
 * execute - executing the command with all path variables.
 * @data:  pointer to program's data
 * Return: if succeded return 0, otherwise -1.
 */
int execute(data_of_program *data)
{
	int retval = 0, status;
	pid_t pidd;

	/* check for program in built ins */
	retval = builtins_list(data);
	if (retval != -1)/* if i found program in built */
		return (retval);

	/* checking program file system */
	retval = find_program(data);
	if (retval)
	{/* if program does not exesit */
		return (retval);
	}
	else
	{/* if we found program */
		pidd = fork(); /* create a child process */
		if (pidd == -1)
		{ /* if the fork call failed */
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{/* child process, execute program*/
			retval = execve(data->tokens[0], data->tokens, data->env);
			if (retval == -1) /* if error when execve*/
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{/* waiting to check statut of the child */
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
