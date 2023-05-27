#include "shell.h"

/**
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments.
 *  Return: 1 on delete, 0 otherwise
 * @varia: the string env var property
 */
int _unsetenv(info_t *info, char *varia)
{
	list_t *node = info->env;
	size_t j = 0;
	char *new;

	if (!node || !varia)
	{
		return (0);
	}
	while (node)
	{
		new = startwith(node->s, varia);
		if (new && *new == '=')
		{
			info->env_changed = _indexdelnode(&(info->env), j);
			j = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		j++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
  * @info: Structure containing potential arguments.
  * @var: the string env var property
  * @value: the string env var value
  *  Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buffer = NULL;
	list_t *node;
	char *new;

	if (!var || !value)
	{
		return (0);
	}

	buffer = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buffer)
	{
		return (1);
	}
	_strcpy(buffer, var);
	_strcat(buffer, "=");
	_strcat(buffer, value);
	node = info->env;
	while (node)
	{
		new = starts_with(node->s, var);
		if (new && *new == '=')
		{
			free(node->s);
			node->s = buffer;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	addEndnode(&(info->env), buffer, 0);
	free(buffer);
	info->env_changed = 1;
	return (0);
}

/**
 **_memset - fills memory with a constant byte
 *@mem: the pointer to the memory area
 *@byt: the byte to fill *s with
 *@num: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *mem, char byt, unsigned int num)
{
	unsigned int j;

	for (j = 0; j < num; j++)
		mem[j] = byt;
	return (mem);
}

/**
 * ffree - frees a string of strings
 * @string: string of strings
 */
void ffree(char **string)
{
	char **b = string;

	if (!string)
	{
		return;
	}
	while (*string)
	{
		free(*string++);
	}
	free(b);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old: byte size of previous block
 * @new: byte size of new block
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old, unsigned int new)
{
	char *poin;

	if (!ptr)
	{
		return (malloc(new));
	}
	if (!new)
	{
		return (free(ptr), NULL);
	}
	if (new == old)
	{
		return (ptr);
	}
	poin = malloc(new);
	if (!poin)
	{
		return (NULL);
	}
	old = old < new ? old : new;
	while (old--)
	{
		poin[old] = ((char *)ptr)[old];
	}
	free(ptr);
	return (poin);
}
