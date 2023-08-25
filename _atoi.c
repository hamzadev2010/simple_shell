#include "shell.h"

/**
*interactive - Check if the shell is in interactive mode.
@info: Pointer to a struct holding information.
*Return: 1 if in interactive mode, 0 otherwise.
*/
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
*is_delim - Check if a character is a delimiter.
*@c: The character to be checked.
*@delim: The delimiter string.
*Return: 1 if the character is a delimiter, 0 otherwise.
*/

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
*_isalpha - Check if a character is alphabetic.
*@c: The character to be checked.
*Return: 1 if @c is an alphabetic character, 0 otherwise.
*/

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
*_atoi - Convert string to integer.
*@s: String to convert.
*Return: Integer, or 0 if no valid numbers.
*/

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
