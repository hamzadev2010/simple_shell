#include "shell.h"

/**
 * str_length - Get the length of a string.
 *
 * This function calculates and returns the length of the input string.
 *
 * @string: Pointer to the string whose length is to be determined.
 *
 * Return: Length of the string.
 */
int str_length(char *string)
{
	int length = 0;

	if (string == NULL)
		return (0);

	while (string[length++] != '\0')
	{
	}
	return (--length);
}

/**
 * str_duplicate - Duplicate a string.
 *
 * This function creates a new copy of the input string.
 *
 * @string: String to be duplicated.
 *
 * Return: Pointer to the duplicated string.
 */
char *str_duplicate(char *string)
{
	char *result;
	int length, i;

	if (string == NULL)
		return (NULL);

	length = str_length(string) + 1;

	result = malloc(sizeof(char) * length);

	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < length ; i++)
	{
		result[i] = string[i];
	}

	return (result);
}

/**
 * str_compare - Compare two strings.
 *
 * This function compares two strings up to the specified number of characters.
 * If the number is 0, the comparison is done until the end of the strings.
 *
 * @string1: First string to be compared.
 * @string2: Second string to be compared.
 * @number: Number of characters to be compared, or 0 for full comparison.
 *
 * Return: 1 if the strings are equal, 0 if the strings are different.
 */
int str_compare(char *string1, char *string2, int number)
{
	int iterator;

	if (string1 == NULL && string2 == NULL)
		return (1);

	if (string1 == NULL || string2 == NULL)
		return (0);

	if (number == 0) /* infinite longitud */
	{
		if (str_length(string1) != str_length(string2))
			return (0);
		for (iterator = 0; string1[iterator]; iterator++)
		{
			if (string1[iterator] != string2[iterator])
				return (0);
		}
		return (1);
	}
	else /* if there is a number of chars to be compared */
	{
		for (iterator = 0; iterator < number ; iterator++)
		{
			if (string1[iterator] != string2[iterator])
			return (0);
		}
		return (1);
	}
}

/**
 * str_concat - Concatenate two strings.
 *
 * This function takes two strings and concatenates them, creating a new string
 * that contains the contents of both input strings.
 *
 * @string1: First string to be concatenated.
 * @string2: Second string to be concatenated.
 *
 * Return: Pointer to the concatenated string.
 */
char *str_concat(char *string1, char *string2)
{
	char *result;
	int length1 = 0, length2 = 0;

	if (string1 == NULL)
		string1 = "";
	length1 = str_length(string1);

	if (string2 == NULL)
		string2 = "";
	length2 = str_length(string2);

	result = malloc(sizeof(char) * (length1 + length2 + 1));
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	/* copy of string1 */
	for (length1 = 0; string1[length1] != '\0'; length1++)
		result[length1] = string1[length1];
	free(string1);

	/* copy of string2 */
	for (length2 = 0; string2[length2] != '\0'; length2++)
	{
		result[length1] = string2[length2];
		length1++;
	}

	result[length1] = '\0';
	return (result);
}


/**
 * str_reverse - Reverse a string in-place.
 *
 * function takes pointer to string reverses contents in-place.
 *
 * @string: Pointer to the string to be reversed.
 * Return: None.
 */
void str_reverse(char *string)
{

	int i = 0, length = str_length(string) - 1;
	char hold;

	while (i < length)
	{
		hold = string[i];
		string[i++] = string[length];
		string[length--] = hold;
	}
}
