#include "shell.h"

/**
 * _strncmp - compare n bytes form string pointed by str2 with str1
 * @str1: string 1
 * @str2: string 2
 * @num: number of bytes to compare
 * Return: 0 if str1 = str2,- integer if str1 <  str2, + integer if str1 > str2
 */
int _strncmp(char *str1, char *str2, int num)
{
	int j = 0;

	while (str1[j] && str2[j] != '\0' && str1[j] == str2[j] && j < num)
	{
		j++;
	}
	if (j == num)
	{
		return (0);
	}
	else
	{
		return (str1[j] - str2[j]);
	}
}
/**
 * _strcat - concatenates two strings
 * @destination: String that will be append
 * @source: string that will be concatenated upon
 * Return: returns pointer to destination
 */
char *_strcat(char *destination, char *source)
{
	char *temp;

	temp = destination;
	while (*temp)
	{
		temp++;
	}

	while (*source)
	{
		*temp = *source;
		temp++;
		source++;
	}
	*temp = '\0';
	return (destination);
}

/**
 * _strcmp - function that compare two strings
 * @str1: pointer to string 1
 * @str2: pointer to string 2
 * Return: 0 if str1 and str2 are equal
 * negative integer if str1 is less than str2
 * positive integer if str1 is greater than str2
 */
int _strcmp(char *str1, char *str2)
{
	int j = 0;

	while (str1[j] != '\0' && str2[j] != '\0' && str1[j] == str2[j])
	{
		j++;
	}
	return (str1[j] - str2[j]);
}

/**
 * _strchr - locates a character in a string.
 * @str: pointer to string
 * @c: character to be located
 * Return: returns the first occurrence of the character c
 */
char *_strchr(char *str, char c)
{
	while (*str != c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}
