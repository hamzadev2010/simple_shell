#include "shell.h"

/**
 * env_get_key - get value of an envirnmnt variable
 * @key: the env variable interest
 * @data: structure of program's data
 * Return: pointer to value of variable or null if not exist
 */
char *env_get_key(char *key, data_of_program *data)
{
	int i, key_length = 0;

	/* validate the arguments */
	if (key == NULL || data->env == NULL)
		return (NULL);

	/* get leng of variable requested */
	key_length = str_length(key);

	for (i = 0; data->env[i]; i++)
	{/* Iterates into environ and checking for coincidence of the name */
		if (str_compare(key, data->env[i], key_length) &&
		 data->env[i][key_length] == '=')
		{/* returns value of key NAME=  when found it*/
			return (data->env[i] + key_length + 1);
		}
	}
	/* returns null if did not found it */
	return (NULL);
}

/**
 * env_set_key - overwrite the value of environment variable
 * or create if does not exist.
 * @key: name of variable to set
 * @value: newest value
 * @data: structure of the program's data
 * Return: one if parameters are null , two if there is an error 0 if succeded.
 */

int env_set_key(char *key, char *value, data_of_program *data)
{
	int i, key_length = 0, is_new_key = 1;

	/* validate the arguments */
	if (key == NULL || value == NULL || data->env == NULL)
		return (1);

	/* get the leng of variable requested */
	key_length = str_length(key);

	for (i = 0; data->env[i]; i++)
	{/* Iterates into environ and checking for coincidence of the name */
		if (str_compare(key, data->env[i], key_length) &&
		 data->env[i][key_length] == '=')
		{/* If key already exists */
			is_new_key = 0;
			/* free the whole variable, it is new created below */
			free(data->env[i]);
			break;
		}
	}
	/* make string of form key=value */
	data->env[i] = str_concat(str_duplicate(key), "=");
	data->env[i] = str_concat(data->env[i], value);

	if (is_new_key)
	{/* if variable is new, create at end of list and we need*/
	/* to put the null value on the next position */
		data->env[i + 1] = NULL;
	}
	return (0);
}

/**
 * env_remove_key - deleted a key from environment
 * @key: the key to deleted
 * @data: the sructure of the program's data
 * Return: one key removed, 0 if key does not exist;
 */
int env_remove_key(char *key, data_of_program *data)
{
	int i, key_length = 0;

	/* validate the arguments */
	if (key == NULL || data->env == NULL)
		return (0);

	/* get the leng of the variable requested */
	key_length = str_length(key);

	for (i = 0; data->env[i]; i++)
	{/* iterates into environ and checking for coincidences */
		if (str_compare(key, data->env[i], key_length) &&
		 data->env[i][key_length] == '=')
		{/* if key already exists, remove them */
			free(data->env[i]);

			/* move other keys down with one position */
			i++;
			for (; data->env[i]; i++)
			{
				data->env[i - 1] = data->env[i];
			}
			/* put null value on top of the list */
			data->env[i - 1] = NULL;
			return (1);
		}
	}
	return (0);
}


/**
 * print_environ - display the current environ
 * @data: structure of the program's data
 * Return: none
 */
void print_environ(data_of_program *data)
{
	int j;

	for (j = 0; data->env[j]; j++)
	{
		_print(data->env[j]);
		_print("\n");
	}
}
