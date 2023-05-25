#include "shell.h"

/**
 * free_tokens - Frees memory allocated for tokens array
 * @token_count: Number of tokens
 * @tokens: Array of tokens
 */
void free_tokens(int token_count, char **tokens)
{
	int i;

	for (i = 0; i < token_count; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
