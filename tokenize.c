#include "shell.h"

/**
 * allocate_token - a function that allocate memory for each token
 * @tokens: token
 * @count: count
 * Return: Success
 */

void allocate_token(char **tokens, int count)
{
	tokens[count] = malloc(MAX_TOKEN_LENGTH * sizeof(char));
	if (tokens[count] == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate memory.\n");
		exit(EXIT_FAILURE);
	}
}

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

	allocate_token(tokens, count);

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
			allocate_token(tokens, count);
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
