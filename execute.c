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
	char *envp[] = {NULL};

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}
