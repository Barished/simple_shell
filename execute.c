#include "shell.h"

/**
 * _execute - function to execute a command
 * @argv: argument var
 * @linepointer: string entered by user
 * @cmdcount: command counter
 * @alllinecmd: array of tokens
 * Return: Success
 */
void _execute(char **alllinecmd, char *linepointer, int cmdcount, char **argv)
{
	struct stat buffer;
	int status, i, set;
	char *command = NULL, *path = NULL;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		command = alllinecmd[0];
		path = _getpath(alllinecmd[0]);
		if (path == NULL)
		{
			set = stat(command, &buffer);
			if (set == -1)
			{
				_print_error(argv[0], cmdcount, commandd);
				_puts(": not found");
				_putchar('\n');
				free(alllineptr);
				free(command);
				for (i = 1; alllinecmd[i] != NULL; i++)
					free(alllinecmd[i]);
				free(alllinecmd);
				exit(100);
			}
			path = command;
		}
		alllinecmd[0] = path;
		if (alllinecmd[0] != NULL)
		{
			if (execve(alllinecmd[0], alllinecmd, environ) == -1)
				_error_execute(argv[0], cmdcount, command);
		}
	}
	else
		wait(&status);
	if (WIFEXITED(status))
	{
		statuscode = WEXITSTATUS(status);
	}
}

