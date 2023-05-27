#include "shell.h"

/**
 * getnodin - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t getnodin(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

/**
 * nodestart- returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *nodestart(list_t *node, char *prefix, char c)
{
	char *r = NULL;

	while (node)
	{
		r = startwith(node->s, prefix);
		if (r && ((c == -1) || (*r == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * fork_cmd - forks a an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, getEnv(info)) == -1)
		{
			_infoFree(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				_printerr(info, "Permission denied\n");
		}
	}
}

/**
 * fcmd - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void fcmd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!_isdelim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(info, get_env(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactif(info) || get_env(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			_printerr(info, "not found\n");
		}
	}
}

/**
 * fbuiltin - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *                      0 if builtin executed successfully,
 *                      1 if builtin found but not successful,
 *                      -2 if builtin signals exit()
 */
int fbuiltin(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", my_exit},
		{"env", _myenv},
		{"help", my_help},
		{"history", _listHistory},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{"cd", my_cd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}
