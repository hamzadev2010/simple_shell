#include "shell.h"

/**
 * start_shell - enter point for starting shell
 *
 * @ac: an arguments counter.
 * @av: an arguments values.
 * @env: an environment.
 *
 * Return: end status.
 */

int start_shell(int ac, char **av, char **env)
{
	char *shell_name = "AZA$ ";
	char *input = NULL;
	char **tokens = NULL;

	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, shell_name, 5);

		input = get_input(av);
		if (input == NULL)
			continue;

		tokens = input_tokenizer(input, av);
		if (tokens == NULL)
		{
			free(input);
			continue;
		}
		free(input);

		execute_commands(tokens, av, env);

		free_arr(tokens);
	}

	if (input != NULL)
		free(input);

	if (tokens != NULL)
		free_arr(tokens);
	return (0);

}
