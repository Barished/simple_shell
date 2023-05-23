#include "shell.h"

/**
 * _strcmp - a function that compares two string
 * @s1: string 1
 * @s2: string 2
 * Return: Success
 */
int _strcmp(const char *s1, const char *s2)
{
	return (strcmp(s1, s2));
}


/**
 * _strlen - a function that returns the lenght of a string
 * @s: input
 * Return: 0 Success
 */
int _strlen(const char *s)
{
	int len = 0;

	while (*s)
	{
		len++;
		s++;
	}

	return (len);
}
/**
 * _strncmp - a function that compares chracters of  two string
 * @str1: string 1
 * @str2: string 2
 * @n: character number
 * Return: Success
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		if (*str1 == '\0')
		{
			break;
		}
		str1++;
		str2++;
		n--;
	}
	return (0);
}
