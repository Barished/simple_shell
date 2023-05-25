#include "shell.h"

/**
 * printAliases - prints all aliases in the format name='value'
 * @aliasList: Alias Node
*/
void printAliases(AliasNode *aliasList)
{
	AliasNode *current;

	current = aliasList;

	while (current != NULL)
	{
		printf("%s='%s'\n", current->name, current->value);
		current = current->next;
	}
}

/**
 * printAlias - prints the value of a specific alias
 * @name: The name of the alias
 * @aliasList: Alias Node
*/
void printAlias(const char *name, AliasNode *aliasList)
{
	AliasNode *current;

	current = aliasList;

	while (current != NULL)
	{
		if (_strcmp(name, current->name) == 0)
		{
			printf("%s='%s'\n", current->name, current->value);
			return;
		}
		current = current->next;
	}
}

/**
 * setAlias - sets or update the value of an alias
 * @name: The name of the alias
 * @value: The value of the alias
 * @aliasList: Alias Node
*/
void setAlias(const char *name, const char *value, AliasNode **aliasList)
{
	AliasNode *current, *newAlias;

	current = *aliasList;
	while (current != NULL)
	{
		if (_strcmp(name, current->name) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			if (current->value == NULL)
			{
				return;
			}
			return;
		}
		current = current->next;
	}
	newAlias = malloc(sizeof(AliasNode));
	if (newAlias == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate memory for alia\n");
		return;
	}
	newAlias->name = strdup(name);
	newAlias->value = strdup(value);
	newAlias->next = NULL;

	if (*aliasList == NULL)
	{
		*aliasList = newAlias;
	}
	else
	{
		current = *aliasList;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newAlias;
	}
}
/**
 * freeAliases - frees the alias command
 * @aliasList: Alias Node
 */
void freeAliases(AliasNode **aliasList)
{
	AliasNode *current;
	AliasNode *next;

	current = *aliasList;
	while (current != NULL)
	{
		next = current->next;
		free(current->name);
		free(current->value);
		free(current);
		current = next;
	}
	*aliasList = NULL;
}

/**
 * handleAlias - handles the alias command
 * @args: The arguments passed to the alias command
 */
void handleAlias(char **args)
{
	int i;
	char *equalSign;
	AliasNode *aliasList = NULL;

	if (args[1] == NULL)
	{
		printAliases(aliasList);
	}
	else
	{
		i = 1;
		while (args[i] != NULL)
		{
			equalSign = strchr(args[i], '=');
			if (equalSign != NULL)
			{
				*equalSign = '\0';
				setAlias(args[i], equalSign + 1, &aliasList);
			}
			else
			{
				printAlias(args[i], aliasList);
			}
			i++;
		}
	}
	freeAliases(&aliasList);
}
