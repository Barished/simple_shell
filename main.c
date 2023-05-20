#include "shell.h"

/**
 * main - the main program
 * @ac: Argument count
 * @av: Argument variable
 * @env: Environment variable
 * Return: Success
 */

int main()
{
	int token_count, i;
	char *line = NULL;
	char **tokens = NULL;

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
