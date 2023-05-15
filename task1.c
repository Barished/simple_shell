#include "simpshell.h"

void disp_prmt(char **av, char **env)
{
	size_t n = 0;
	char *buffer = NULL;
	char *argv[] = {NULL, NULL};
	int i = 0;
	ssize_t input;
	int status;
	int val;
	pid_t pid;


	while (1)
	{
		printf("simpshell$ ");
	input = getline(&buffer, &n, stdin);

	if (input == -1)
	{
		free(buffer);
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
		free(buffer);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		val = execve(argv[0], argv, env);
		if (val == -1)
			printf("%s%s", av[0],": No such file or directory\n");
	}
	else
		wait(&status);
	}
}
