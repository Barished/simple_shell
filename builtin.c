#include "shell.h"

/**
 * _built - checks for builtin functions and process
 * @linepointer: string user input
 * @alllinecmd: tokens placed in arrays
 * Return: 0 when builtin found, otherwise -1
 */
int _built(char **alllinecmd, char *linepointer)
{
	void (*func_ptr)(char *);

	func_ptr = _checkbuiltin(alllinecmd[0]);
	if (func_ptr == NULL)
	{
		return (-1);
	}

	if (_strcmp("exit", alllinecmd[0]) == 0)
	{
		_freePointer(alllinecmd);
	}

	func_ptr(linepointer);
	return (0);
}

/**
 * _envir -  prints the environmental var
 * @alllineptr: parameter
 * Return: success
 */
void _envir(char *alllineptr)
{
	int j, i;

	(void)alllineptr;

	for (j = 0; environ[j] != NULL; j++)
	{
		for (i = 0; environ[j][i] != '\0'; i++)
		{
			write(STDOUT_FILENO, &environ[j][i], 1);
		}
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * _checkbuiltin - returns the right builtin function
 * @function: builtin function
 * Return: pointer to the function
 */
void (*_checkbuiltin(char *function))(char *s)
{
	int i;

	built_t built_cmds[] = {
		{"env", _envir},
		{"exit", _exit_more},
		{NULL, NULL}
	};

	for (i = 0; built_cmds[i].built_in != NULL; i++)
	{
		if (_strcmp(built_cmds[i].built_in, function) == 0)
		{
			return (built_cmds[i].fptr);
		}
	}
	return (NULL);
}

#include "shell.h"

/**
 * _cmd_path - builds the executable path of the command
 * @cmd_path: path of the executable command
 * @command: executable command
 * Return: full executable path of the command
 */
char *_cmd_path(char *cmd_path, char *command)
{
	int len = 0;
	char *path_way = NULL;

	if (cmd_path == NULL || command == NULL)
	{
		return (NULL);
	}

	len = (_strlen(cmd_path) + _strlen(command) + 2);
	path_way = malloc(sizeof(char) * len);
	if (path_way == NULL)
	{
		return (NULL);
	}

	_strcpy(path_way, cmd_path);
	_strcat(path_way, "/");
	_strcat(path_way, command);
	_strcat(path_way, "\0");

	return (path_way);
}
