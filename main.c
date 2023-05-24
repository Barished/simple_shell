#include "shell.h"

/**
 * main - the main program
 * @env: Environment variable
 * @argc: argumemt count
 * @argv: argument variable
 * Return: Success
 */

int main(int argc, char **argv, char **env)
{
	int token_count, i, status;
	char *line = NULL;
	char **tokens = NULL;
	char **args;

	(void)argc, (void)argv;
	while (1)
	{
		printf("%s> ", current_directory);
		line = read_line();
		tokens = malloc(MAX_TOKENS * sizeof(char *));
		if (tokens == NULL)
		{
			fprintf(stderr, "Error: Failed to allocate memory.\n");
			exit(EXIT_FAILURE);
		}
		token_count = tokenize(line, tokens, " ");
		handleExit(tokens[0]);
		if (_strcmp(tokens[0], "env") == 0)
		{
			print_environment(env);
			continue;
		}
		if (_strcmp(tokens[0], "cd") == 0)
		{
			handleCD(tokens[1]);
			continue;
		}
		if (_strcmp(tokens[0], "alias") == 0)
		{
			handleAlias(tokens);
			continue;
		}
		args = malloc((token_count + 1) * sizeof(char *));
		if (args == NULL)
		{
			fprintf(stderr, "Error: Failed to allocate memory.\n");
			exit(EXIT_FAILURE);
		}

		for (i = 0; i < token_count; i++)
		{
			args[i] = tokens[i];
		}
		args[token_count] = NULL;
		status = execute_commands(tokens);

		free(args);
		for (i = 0; i < token_count; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
		free(line);

		if (status == -1)
		{
			fprintf(stderr, "command execution error.\n");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
