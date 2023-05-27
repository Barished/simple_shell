#include "shell.h"

/**
 * _interactif - returns true if shell is interactive.
 * @info: pointer to struct
 * Return: 1 if shell is in interactive mode,otherwise 0
 */
int _interactif(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *_atoi - converts string to integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise 1
 */
int _atoi(char *s)
{
	int i, lead = 1, count = 0, check;
	unsigned int outcome = 0;

	for (i = 0;  s[i] != '\0' && count != 2; i++)
	{
		if (s[i] == '-')
			lead *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			count = 1;
			outcome *= 10;
			outcome += (s[i] - '0');
		}
		else if (count == 1)
			count = 2;
	}

	if (lead == -1)
		check = -outcome;
	else
		check = outcome;

	return (check);
}

/**
 *_isalpha - checks for alphabet character
 *@c: The character to input
 *Return: 1 if c is an alphabet, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _isdelim - checks if character is a delimiter
 * @c: the check char
 * @delim: delimiter string
 *
 * Return: 1 if true, 0 if false
 */
int _isdelim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _delcomment - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 * Return: Always 0;
 */
void _delcomment(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
