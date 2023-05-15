#include "shell.h"

/**
 * disp_prmt - a function to get input from user, tokenize and execute it
 * @av: Argument variable
 * @env: Environment Variable
 * Return: 0 on Success
 */

void disp_prmt(char **av, char **env)
{
	size_t n = 0;
	ssize_t input;
	char *buffer = NULL;
	char *argv[] = {NULL, NULL};
	int status, val, i = 0;
	pid_t pid;

	printf("shell$ ");
	input = getline(&buffer, &n, stdin);
	if (input == -1)
	{
		exit(EXIT_FAILURE);
	}
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			buffer[i] = '\0';
		i++;
	}
	argv[0] = buffer;
	pid = fork();
	if (pid == -1)
	{
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		val = execve(argv[0], argv, env);
		if (val == -1)
		{
			printf("%s: No such file or directory\n", av[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
	free(buffer);
}
