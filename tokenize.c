#include "shell.h"

/**
 * tokenize - tokenize
 * @input: input
 * @tokens: tokens
 * @delimiter: delimeter
 * Return: Success
 */

int tokenize(const char *input, char **tokens, const char *delimiter)
{
	int count = 0;
	char *token;

	token = strtok((char *)input, delimiter);
	while (token != NULL && count < MAX_ARGS - 1)
	{
		tokens[count] = token;
		count++;
		token = strtok(NULL, delimiter);
	}
	tokens[count] = NULL;
	return (count);
}

/**
 * execute - execute
 * @args: argument
 * Return: Success
 */

int execute(char **args)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) < 0)
		{
			perror("execvp failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
	return (0);
}

/**
 * main - entry
 * Return: success
 */
int main(void)
{
	char input[BUFSIZE];
	char *tokens[MAX_ARGS];
	int tokenCount;

	while (1)
	{
		printf("sh> ");
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';

		tokenCount = tokenize(input, tokens, " ");
		if (tokenCount > 0)
		{
			if (strcmp(tokens[0], "exit") == 0)
			{
				break;
			}
			execute(tokens);
		}
	}

	return (0);
}
