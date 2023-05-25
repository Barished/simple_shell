#include "shell.h"

/**
 * execute - Executes the given command
 * @args: Array of command arguments
 * Return: Status of command execution
 */
int execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execute_child(args);
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

/**
 * execute_child - Executes the command in the child process
 * @args: Array of command arguments
 */
void execute_child(char **args)
{
	char *path, *dir, *path_copy;
	char exec_path[MAX_PATH_LENGTH];

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
		snprintf(exec_path, sizeof(exec_path), "%s/%s", dir, args[0]);
		if (execve(exec_path, args, environ) != -1)
		{
			perror("execve");
		}

		dir = strtok(NULL, ":");
	}

	fprintf(stderr, "%s: command not found\n", args[0]);
	exit(EXIT_FAILURE);
}
