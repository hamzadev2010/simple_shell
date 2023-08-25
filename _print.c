#include "shell.h"


/**
 * _print - to display on screen depend on status
 *
 * @status: state(0,1,2).
 * @av: an arg values.
 * @message: message to display
 *
 * Return: a void.
 */

void _print(int status, char **av, char *message)
{
	write(status, av[0], _strlen(av[0]));
	write(status, message, _strlen(message));
}


/**
 * print_execute_error - to display on error for exe.
 *
 * @status: state(0,1,2).
 * @av: an arg values.
 * @command: faild command.
 *
 * Return: a void.
 */
void print_execute_error(int status, char **av, char *command)
{
	/*./hsh: 1: ./file: not find */
	 write(status, av[0], _strlen(av[0]));
	 write(status, ": 1: ", 5);
	 write(status, command,  _strlen(command));
	 write(status, ": not found\n", _strlen(": not found\n"));
}
