#include "shell.h"

/**
 * _putchar - prints a single character
 * @ch: character to print
 * Return: always 1
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}


/**
 * _puts - Prints a string character by character.
 * @s: String to be printed.
 * Return: success
 */
void _puts(char *s)
{
	int j;

	if (s == NULL)
	{
		s = "(null)";
	}
	for (j = 0; str[j]; j++)
	{
		_putchar(s[j]);
	}
}


/**
 * _printint - function that prints an integer
 * @nb: number to be printed
 * Return: count of numbers printed
 */
int _printint(int nb)
{
	int div = 1, count;
	unsigned int n;

	div = 1;
	count = 0;

	n = nb;

	while (n / div > 9)
	{
		div *= 10;
	}

	while (div != 0)
	{
		count += _putchar('0' + n / div);
		n %= div;
		div /= 10;
	}

	return (count);
}
