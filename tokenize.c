#include "shell.h"

/**
 * tokenize - a function tha separates command into several tokens
 * @input: A pointer to the line written in stdin
 * @tokens: tokens
 * @delimiter: THe expected delimiters
 * Return: 0 on Success
 */

int tokenize(const char *input, char **tokens, const char *delimiter)
{
	int count = 0;
	int len = 0;
	int i = 0;

	tokens[count] = malloc(MAX_TOKEN_LENGTH * sizeof(char));
	if (tokens[count] == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate memory.\n");
		exit(EXIT_FAILURE);
	}
	while (input[i])
	{
		if (input[i] == *delimiter)
		{
			tokens[count][len] = '\0';
			count++;
			len = 0;

			if (count >= MAX_TOKENS)
			{
				break;
			}

			tokens[count] = malloc(MAX_TOKEN_LENGTH * sizeof(char));
			if (tokens[count] == NULL)
			{
				fprintf(stderr, "Failed to allocate memory for token.\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			tokens[count][len] = input[i];
			len++;
		}

		if (len >= MAX_TOKEN_LENGTH - 1)
		{
			break;
		}

		i++;
	}

	tokens[count][len] = '\0';
	count++;

	return (count);
}
