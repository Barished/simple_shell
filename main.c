#include "shell.h"

/**
 * main - the main program
 * @env: Environment variable
 * @argc: argument count
 * @argv: argument variable
 * Return: Success
 */
int main(int argc, char **argv, char **env)
{
	int token_count, i, status;
	char *line = NULL;
	char **args, **tokens = NULL;
	(void)argc, (void)argv;

	while (1)
	{
		print_prompt();
		line = read_line();
		allocate_tokens(MAX_TOKENS, &tokens);
		token_count = tokenize(line, tokens, " ");
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
		status = process_command(args, env, token_count, tokens, line);
		if (status == -1)
		{
			fprintf(stderr, "command execution error.\n");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
