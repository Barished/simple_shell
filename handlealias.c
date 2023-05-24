#include "shell.h"

/**
 * printAliases - prints all aliases in the format name='value'
 */
void printAliases(void)
{
	int i;
	int aliasCount;

	for (i = 0; i < aliasCount; i++)
	{
		printf("%s='%s'\n", aliases[i].name, aliases[i].value);
	}
}

/**
 * printAlias - prints the value of a specific alias
 * @name: The name of the alias
 */
void printAlias(const char *name)
{
	int i;

	for (i = 0; i < aliasCount; i++)
	{
		if (_strcmp(name, aliases[i].name) == 0)
		{
			printf("%s='%s'\n", aliases[i].name, aliases[i].value);
			return;
		}
	}
}

/**
 * setAlias - sets or update the value of an alias
 * @name: The name of the alias
 * @value: The value of the alias
 */
void setAlias(const char *name, const char *value)
{
	int i;

	for (i = 0; i < aliasCount; i++)
	{
		if (_strcmp(name, aliases[i].name) == 0)
		{
			_strcpy(aliases[i].value, value);
			return;
		}
	}

	if (aliasCount >= MAX_ALIAS_COUNT)
	{
		fprintf(stderr, "Error: Maximum alias count reached.\n");
		return;
	}

	struct Alias newAlias;

	strcpy(newAlias.name, name);
	strcpy(newAlias.value, value);
	aliases[aliasCount++] = newAlias;
}

/**
 * handleAlias - handles the alias command
 * @args: The arguments passed to the alias command
 */
void handleAlias(char **args)
{
	char *equalSign;
	int i;

	if (args[1] == NULL)
	{
		printAliases();
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
				setAlias(args[i], equalSign + 1);
			}
			else
			{
				printAlias(args[i]);
			}
			i++;
		}
	}
}
