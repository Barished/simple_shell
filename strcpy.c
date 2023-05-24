#include "shell.h"

/**
 * _strcpy - Copies a string from source to destination
 * @destination: The destination character array
 * @source: The source string to be copied
 * Return: A pointer to the destination string
 */
char *_strcpy(char *destination, const char *source)
{
	char *start;

	start = destination;
	while (*source)
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';

	return (start);
}
