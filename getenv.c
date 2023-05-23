#include "shell.h"

/**
 * _getenv - a function to get environment
 * @name: Path name
 * Return: Success
 */

char *_getenv(const char *name)
{
	int name_length, i, x;

	if (name == NULL)
	{
		return (NULL);
	}

	name_length = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		x = _strncmp(environ[i], name, name_length);
		if (x == 0 && environ[i][name_length] == '=')
		{
			return (environ[i] + name_length + 1);
		}
	}
	return (NULL);
}
