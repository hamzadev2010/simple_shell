#include "shell.h"

/**
 * _strcmp - compare 2 strings.
 *
 * @s1: 1 string
 * @s2: 2 string
 * @len: length to comparing in
 *
 * Return: zero in match -1 else.
 *
 */
int _strcmp(char *s1, char *s2, size_t len)
{
	size_t i = 0;

	for (i = 0 ; s1[i] && s2[i] && i < len ; i++)
	{
		if (s1[i] != s2[i])
		{
			return (-1);
		}
	}

	if (i == len)
		return (0);

	return (-1);
}
