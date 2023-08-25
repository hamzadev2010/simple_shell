#include "shell.h"

/**
 * _strcat - concatinate 2 strings
 *
 * @dest: a first string and have the final result.
 * @src: a string that we need to add.
 *
 * Return: new string.
 */
char *_strcat(char *dest, const char *src)
{
	char *dest_temp = dest;
	const char *src_temp = src;

	while (*dest_temp != '\0')
		dest_temp++;

	while (*src_temp != '\0')
	{
		*dest_temp++ = *src_temp++;
	}
	*dest_temp = '\0';

	return (dest);
}
