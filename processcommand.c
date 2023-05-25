#include "shell.h"

/**
 * process_command - Processes the given command
 * @args: Array of command arguments
 * @env: Environment variable
 * @count: Number of tokens
 * @toks: Array of tokens
 * @lin: Line of input
 * Return: Status of command execution
 */
int process_command(char **args, char **env, int count, char **toks, char *lin)
{
	int status = 0;

	handleExit(args[0]);
	if (_strcmp(args[0], "env") == 0)
	{
		print_environment(env);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		handleCD(args[1]);
	}
	else if (_strcmp(args[0], "alias") == 0)
	{
		handleAlias(toks);
	}
	else
	{
		status = execute_commands(args);
	}

	free(args);
	free_tokens(count, toks);
	free(lin);

	if (status == -1)
	{
		fprintf(stderr, "command execution error.\n");
		exit(EXIT_FAILURE);
	}

	return (status);
}
