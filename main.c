#include "shell.h"

/**
 * main - enter point to starting program
 *
 * @ac: an arguments counter.
 * @av: an arguments values.
 * @env:an  environment.
 *
 * Return: zero o on success
 */
int main(int ac, char **av, char **env)
{
	int status;

	status = start_shell(ac, av, env);

	return (status);
}
