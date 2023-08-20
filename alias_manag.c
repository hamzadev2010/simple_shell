#include "shell.h"

/**
 * print_alias - add, delete or show aliases
 * @data: structure for the program's data
 * @alias: name of the alias to be displayed
 * Return: zero if validate, or another number if its declared in the arguments
 */
int print_alias(data_of_program *data, char *alias)
{
	int i, j, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = str_length(alias);
		for (i = 0; data->alias_list[i]; i++)
		{
			if (!alias || (str_compare(data->alias_list[i], alias, alias_length)
				&&	data->alias_list[i][alias_length] == '='))
			{
				for (j = 0; data->alias_list[i][j]; j++)
				{
					buffer[j] = data->alias_list[i][j];
					if (data->alias_list[i][j] == '=')
						break;
				}
				buffer[j + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->alias_list[i] + j + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * get_alias - add, delete or display aliases
 * @data: structure for the program's data
 * @name: name on the requested alias.
 * Return: zero if true, or another number if its declared in the arguments
 */
char *get_alias(data_of_program *data, char *name)
{
	int i, alias_length;

	/* validate the arguments */
	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = str_length(name);

	for (i = 0; data->alias_list[i]; i++)
	{/* Iterates on the environ and checking for the varname if exist */
		if (str_compare(name, data->alias_list[i], alias_length) &&
			data->alias_list[i][alias_length] == '=')
		{/* returns the value of the key name=  when found it */
			return (data->alias_list[i] + alias_length + 1);
		}
	}
	/* returns null if did not found it */
	return (NULL);

}

/**
 * set_alias - add, or override the alias
 * @alias_string: alias to be seted on the  form (name='value')
 * @data: structure for the program's data
 * Return: zero if validate, or another number if its declared in the arguments
 */
int set_alias(char *alias_string, data_of_program *data)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	/* validate the arguments */
	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);
	/* Iterates alias to found = char */
	for (i = 0; alias_string[i]; i++)
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
		{/* checking if the value of alias is on another alias */
			temp = get_alias(data, alias_string + i + 1);
			break;
		}

	/* Iterates through the alias list and check for coincidence of the varname */
	for (j = 0; data->alias_list[j]; j++)
		if (str_compare(buffer, data->alias_list[j], i) &&
			data->alias_list[j][i] == '=')
		{/* if the alias already found */
			free(data->alias_list[j]);
			break;
		}

	/* add the alias */
	if (temp)
	{/* if the alias found */
		buffer_add(buffer, "=");
		buffer_add(buffer, temp);
		data->alias_list[j] = str_duplicate(buffer);
	}
	else /* if alias not found */
		data->alias_list[j] = str_duplicate(alias_string);
	return (0);
}
