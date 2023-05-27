#include "shell.h"

/**
 * _strcpy - copies a string
 * @destination: the destination
 * @source: the source
 * Return: pointer to destination
 */
char *_strcpy(char *destination, char *source)
{
	int j;

	if (destination == source || source == 0)
	{
		return (destination);
	}

	for (j = 0; source[j] != '\0'; j++)
	{
		destination[j] = source[j];
	}
	destination[j] = '\0';
	return (destination);
}

/**
 * _strdup - duplicates a string
 * @s: the string to duplicate
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *s)
{
	int len = 0;
	char *copy;

	if (s == NULL)
	{
		return (NULL);
	}
	while (*s++)
	{
		len++;
	}
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
	{
		return (NULL);
	}
	for (len++; len--;)
	{
		copy[len] = *--s;
	}
	return (copy);
}

/**
 *_puts - prints an input string
 *@s: the string to be printed
 * Return: Nothing
 */
void _puts(char *s)
{
	int j = 0;

	if (!s)
	{
		return;
	}
	while (s[j] != '\0')
	{
		_putchar(s[j]);
		j++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @ch: The character to print
 * Return: On success 1.
 */
int _putchar(char ch)
{
	static int j;
	static char buffer[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(1, buffer, j);
		j = 0;
	}
	if (ch != BUF_FLUSH)
	{
		buffer[j++] = ch;
	}
	return (1);
}
