#include "shell.h"
/**
 * _strlen - Calculate length of a string.
 * @p: String to be evaluated.
 * Return: Length of the string.
 */

int _strlen(char *p)
{
	int i = 0;

	if (p == NULL)
		return (0);
	while (p[i] != '\0')
	{
		i++;
	}
	return (i);
}
