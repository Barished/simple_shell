#include "shell.h"

/**
 * getEnv - returns the string array copy of our environm
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
char **getEnv(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = toString(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 *_eputs - prints an input string
 * @s: the string to be printed
 * Return: Nothing
 */
void _eputs(char *s)
{
	int j = 0;

	if (!s)
	{
		return;
	}
	while (s[j] != '\0')
	{
		_eputchar(s[j]);
		j++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @ch: The character to print
 * Return: On success 1.
 */
int _eputchar(char ch)
{
	static int j;
	static char buff[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buff, j);
		j = 0;
	}
	if (ch != BUF_FLUSH)
	{
		buff[j++] = ch;
	}
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @ch: The character to print
 * @fd: The filedescriptor to write to
 * Return: On success 1.
 */
int _putfd(char ch, int fd)
{
	static int j;
	static char buff[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buff, j);
		j = 0;
	}
	if (ch != BUF_FLUSH)
	{
		buff[j++] = ch;
	}
	return (1);
}
