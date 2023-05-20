#include "shell.h"

/**
 * main - the main program
 * @env: Environment variable
 * Return: Success
 */

int main(int argc, char **argv, char **env)
{
	int token_count, i;
	char *line = NULL;
	char **tokens = NULL;

	(void)argc;
	(void)argv;
	while (1)
	{
		printf(">");
		line = read_line();
		tokens = malloc(MAX_TOKENS * sizeof(char*));
		if (tokens == NULL)
		{
			fprintf(stderr, "Error: Failed to allocate memory.\n");
			exit(EXIT_FAILURE);
		}
		token_count = tokenize(line, tokens, " ");
		handleExit(tokens[0]);
		if (strcmp(tokens[0], "env") == 0)
		{
			print_environment(env);
			continue;
		}
		if (strcmp(tokens[0], "cd") == 0)
		{
			handleCD(tokens[1]);
			continue;
		}
		execute(tokens);
		for (i = 0; i < token_count; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
		free(line);
	}
	return (0);
}
