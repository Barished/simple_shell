#include "shell.h"

/**
* execute - a function that execute command input from the user
* @args: Argument
* Return: 0 on success
*/

int execute(char **args)
{
	pid_t pid;
	int status;
	char *path, *dir, *path_copy;
	char executable_path[MAX_PATH_LENGTH];

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		path = _getenv("PATH");
		if (path == NULL)
		{
			perror("getenv");
			exit(EXIT_FAILURE);
		}

		path_copy = strdup(path);
		if (path_copy == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		dir = strtok(path_copy, ":");
		while (dir != NULL)
		{
			snprintf(executable_path, sizeof(executable_path), "%s/%s", dir, args[0]);
			if (execve(executable_path, args, environ) != -1)
			{
				perror("execve");
			}

			dir = strtok(NULL, ":");
		}

		fprintf(stderr, "%s: command not found\n", args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
	}

	return (0);
}
