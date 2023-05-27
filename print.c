#include "shell.h"

/**
 * _convno - converts a number
 * @num: the number
 * @base: the base
 * @flags: the argument flags
 *
 * Return: the string
 */
char *_convno(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char amount = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do      {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * _printdeci - function prints a decimal number
 * @input: the input
 * @fd: the file descriptor to write to
 *
 * Return: number of characters printed
 */
int _printdeci(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int bale, wave;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		bale = -input;
		__putchar('-');
		count++;
	}
	else
		bale = input;
	wave = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (bale / i)
		{
			__putchar('0' + wave / i);
			count++;
		}
		wave %= i;
	}
	__putchar('0' + wave);
	count++;

	return (count);
}

/**
 * _printerr - prints an error message
 * @info: the parameter & return info struct
 * @estr: the error string
 * Return: 0 if no numbers in string, converted number else
 *        -1 on error
 */
void _printerr(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	_printdeci(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * _satoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number else
 *       -1 on error
 */
int _satoi(char *s)
{
	int i = 0;
	unsigned long int output = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			output *= 10;
			output += (s[i] - '0');
			if (output > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (output);
}

/**
 *_pfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to freed
 *
 * Return: 1 if freed, otherwise 0.
 */
int _pfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
