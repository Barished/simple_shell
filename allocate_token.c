#include "shell.h"

/**
 * allocate_tokens - Allocates memory for tokens array
 * @token_count: Number of tokens
 * @tokens: Array of tokens
 */
void allocate_tokens(int token_count, char ***tokens)
{
	*tokens = malloc((token_count + 1) * sizeof(char *));
	if (*tokens == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate memory.\n");
		exit(EXIT_FAILURE);
	}
}
