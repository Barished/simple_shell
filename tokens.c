#include "shell.h"

/**
 * calcTokencmd -  calculate token command
 * @alllineptr: pointer to string
 * @delimeter: delimiter between strings
 * Return: success
 */

int calcTokencmd(char *alllineptr, const char *delimeter)
{
	int count = 0;
	char *tokens, *copy;

	copy = _strdup(alllineptr);
	if (copy == NULL)
	{
		return (-1);
	}

	tokens = strtok(copy, delimeter);
	while (tokens != NULL)
	{
		count++;
		tokens = strtok(NULL, delimeter);
	}

	free(copy);
	return (count);
}
/**
 * _tokenParsing - tokenize the command
 * @token: number of token
 * @alllineptr: command pointer to be tokenized
 * @delimeter: the delimiter
 * Return: success
 */
char **_tokenParsing(int token, char *alllineptr, const char *delimeter)
{
	int j = 0;
	char *copy, *tokens;
	char **array_token;

	copy = _strdup(alllineptr);
	if (copy == NULL)
	{
		return (NULL);
	}

	token = calcTokencmd(alllineptr, delimeter);
	if (token == -1)
	{
		free(alllineptr);
		return (NULL);
	}
	array_token = malloc(sizeof(char *) * (token + 1));
	if (array_token == NULL)
	{
		return (NULL);
	}

	tokens = strtok(copy, delimeter);
	while (tokens != NULL)
	{
		array_token[j] = _strdup(tokens);
		tokens = strtok(NULL, delimeter);
		j++;
	}
	array_token[j] = NULL;
	if (array_token == NULL)
	{
		free(alllineptr);
		return (NULL);
	}
	free(copy);
	return (array_token);
}

