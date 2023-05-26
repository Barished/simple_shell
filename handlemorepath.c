#include "shell.h"

/**
 * _executePath - full path of the executable command
 * @command: executable command
 * @token: array of PATH tokens
 * Return: full path
 */
char *_executePath(char **token, char *command)
{
	struct stat stat_buf;
	char *exec_pwd = NULL, *buffer = NULL;
	size_t pathsize = 0;
	int status, j;

	exec_pwd = getcwd(buffer, pathsize);
	if (exec_pwd == NULL)
	{
		return (NULL);
	}

	if (command[0] == '/')
	{
		command = command + 1;
	}

	for (j = 0; token[j]; j++)
	{
		status = chdir(token[j]);
		if (status == -1)
		{
			perror("Error ");
			return (NULL);
		}
		status = stat(command, &stat_buf);
		if (status == 0)
		{
			chdir(exec_pwd);
			free(exec_pwd);
			return (token[j]);
		}
	}
	chdir(exec_pwd);
	free(exec_pwd);
	return (NULL);
}

/**
 * _tokenPath - tokenize the environemtal variable PATH
 * @s: PATH string
 * Return: array of PATH tokens
 */
char **_tokenPath(char *s)
{
	int cnt = 0;
	char **token;
	const char *delimeter = "\n:";

	s = getenv("PATH");
	token = _tokenParsing(cnt, s, delimeter);
	if (token == NULL)
	{
		return (NULL);
	}

	return (token);
}

/**
 * _execPath - extract path and check if the executable exists
 * @command: executable command
 * Return:  path of executabe file
 */
char *_execPath(char *command)
{
	char **tokpath = NULL;
	char *s = NULL, *exec_path = NULL, *command_path = NULL;

	tokpath = _tokenPath(s);
	if (tokpath == NULL)
	{
		return (NULL);
	}

	exec_path = _executePath(tokpath, command);
	if (exec_path == NULL)
	{
		_freePointer(tokpath);
		return (NULL);
	}

	command_path = _cmd_path(exec_path, command);
	if (command_path == NULL)
	{
		_freePointer(tokpath);
		return (NULL);
	}

	_freePointer(tokpath);
	return (command_path);
}

/**
 * _freePointer - frees an array of strings
 * @s: array of strings
 * Return: Success
 */
void _freePointer(char **s)
{
	int j = 0;

	while (s[j] != NULL)
	{
		free(s[j]);
		j++;
	}
	free(s);
}
