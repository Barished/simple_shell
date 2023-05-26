#include "shell.h"

/**
 * _customAtoi - converts a string to integer
 * @s: string to convert
 * Return: integer value after conversion
 */
int _customAtoi(char *s)
{
	int j;
	unsigned int num = 0;

	for (j = 0; s[j]; j++)
	{
		if (s[j] >= '0' && s[j] <= '9')
		{
			num = num * 10 + (s[j] - '0');
		}
		if (s[j] > '9' || s[j] < '0')
		{
			return (-1);
		}
	}
	return (num);
}

/**
 * _exit - exits the simple shell
 * @alllineptr: command line input string from user input
 * Return: exit shell if success, -1 if error
 */
void _exit(char *alllineptr)
{
	int status = 0, count = 0;
	char **token;
	const char *delimeter = "\n\t ";

	token = _parse_to_token(count, alllineptr, delimeter);
	if (token == NULL)
	{
		free(alllineptr);
		_free_double_ptr(token);
		return;
	}

	if (token[1] != NULL)
	{
		status = _customAtoi(token[1]);
	}

	if (status == -1)
	{
		perror("Error ");
		_free_double_ptr(token);
		return;
	}

	_free_double_ptr(token);
	free(alllineptr);
	exit(statuscode);
}

