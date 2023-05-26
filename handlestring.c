#include "shell.h"

/**
 * _exitGetline - exits the shell on getline error or Ctrl + D (EOF condition)
 * @alllineptr: string input from user
 * Return: void
 */
void _exitGetline(char *alllineptr)
{
	free(alllineptr);
	exit(EXIT_SUCCESS);
}


/**
 * _ignoreSignal - function that ignores ^C (SIGINT) to the process
 * @signal: integer value of signal
 * Return: Nothing
 */

void _ignoreSignal(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * _strcpy - copy from one string to the other
 * @source: pointer to string
 * @destination: pointer to string
 * Return: the pointer to destination
 */
char *_strcpy(char *destination, char *source)
{
	int j;

	for (j = 0; source[j] != '\0'; j++)
	{
		destination[j] = source[j];
	}
	destination[j] = '\0';
	return (destination);
}

/**
 * _strlen - calculate the length of a string
 * @string: pointer to string
 * Return: integer length of the string
 */
unsigned int _strlen(char *string)
{
	unsigned int lenght = 0;

	while (*string)
	{
		lenght++;
		string++;
	}
	return (lenght);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @string: pointer to string
 * Return: returns NULL if str is NULL or a pointer to the duplicated string
 */
char *_strdup(char *string)
{
	char *copy;
	unsigned int j;

	if (string == NULL)
	{
		return (NULL);
	}
	copy = (char *)malloc(sizeof(char) * (_strlen(string) + 1));

	if (copy == NULL)
	{
		return (NULL);
	}

	for (j = 0; string[j]; j++)
	{
		copy[j] = string[j];
	}
	copy[j] = '\0';
	return (copy);
}
