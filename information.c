#include "shell.h"

/**
 * _infoClear - initializes info_t struct
 * @info: struct address
 */
void _infoClear(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * _infoSet - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void _infoSet(info_t *info, char **av)
{
	int j = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (j = 0; info->argv && info->argv[j]; j++)
			;
		info->argc = j;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * _infoFree - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void _infoFree(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
		{
			free(info->arg);
		}
		if (info->env)
		{
			_freeList(&(info->env));
		}
		if (info->history)
		{
			_freeList(&(info->history));
		}
		if (info->alias)
		{
			_freeList(&(info->alias));
		}
		ffree(info->environ);
		{
			info->environ = NULL;
		}
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
		{
			close(info->readfd);
		}
		_putchar(BUF_FLUSH);
	}
}
