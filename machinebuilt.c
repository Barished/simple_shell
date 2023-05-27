#include "shell.h"

/**
 * _listHistory - displays the history list, one command by line, preceded
 * @info: Structure containing potential arguments. Used to maintain
 * Return: Always 0
 */
int _listHistory(info_t *info)
{
	listPrint(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @s: the string alias
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *s)
{
	char *new, c;
	int ret;

	new = _strchr(s, '=');
	if (!new)
	{
		return (1);
	}
	c = *new;
	*new = 0;
	ret = _indexdelnode(&(info->alias),
		_nodeIndex(info->alias, startNode(info->alias, s, -1)));
	*new = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @s: the string alias
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *s)
{
	char *new;

	new = _strchr(s, '=');
	if (!new)
	{
		return (1);
	}
	if (!*++new)
	{
		return (unset_alias(info, s));
	}
	unset_alias(info, s);
	return (addEndnode(&(info->alias), s, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->s, '=');
		for (a = node->s; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int j = 0;
	char *new = NULL;
	list_t *currentnode = NULL;

	if (info->argc == 1)
	{
		currentnode = info->alias;
		while (currentnode)
		{
			print_alias(currentnode);
			currentnode = currentnode->next;
		}
		return (0);
	}
	for (j = 1; info->argv[j]; j++)
	{
		new = _strchr(info->argv[j], '=');
		if (new)
			set_alias(info, info->argv[j]);
		else
			print_alias(startNode(info->alias, info->argv[j], '='));
	}

	return (0);
}
