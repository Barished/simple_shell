#include "shell.h"

/**
 * shell - main shell loop
 * @info: the parameter & return the info struct
 * @av: the argument vector from main()
 * Return: 0 on success, 1 on error, or error code
 */
int shell(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		_infoClear(info);
		if (interactif(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = _getinput(info);
		if (r != -1)
		{
			_infoSet(info, av);
			builtin_ret = fbuiltin(info);
			if (builtin_ret == -1)
				fcmd(info);
		}
		else if (interactif(info))
			_putchar('\n');
		_infoFree(info, 0);
	}
	historyWrite(info);
	_infoFree(info, 1);
	if (!interactif(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * pstring - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int pstring(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

/**
 * plist - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t plist(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(_convno(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->s ? h->s : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * toString - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **toString(list_t *head)
{
	list_t *node = head;
	size_t i = llength(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->s) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->s);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * llength - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t llength(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}
