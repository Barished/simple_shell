#include "shell.h"

/**
 * execute_commands - execute multiple commands with logical operators
 * @commands: Array of command strings
 * Return: 0 on success, -1 on failure
 */

int execute_commands(char **commands)
{
	int status, i = 0;
	int result = 0;
	int operator = 0;
	char **args;

	while (commands[i] != NULL)
	{
		if (_strcmp(commands[i], "&&") == 0)
		{
			operator = 1;
		}
		else if (_strcmp(commands[i], "||") == 0)
		{
			operator = 2;
		}
		else
		{
			args = malloc(MAX_TOKENS * sizeof(char *));
			if (args == NULL)
			{
				fprintf(stderr, "Failed to alloc memory.\n");
				free(args);
				exit(EXIT_FAILURE);
			}
			if (args != NULL)
			{
				status = execute(commands);
				free(args);

				if (operator == 1 && status != 0)
				{
					result = -1;
					break;
				}
				else if (operator == 2 && status == 0)
				{
					result = -1;
					break;
				}
			}
		}

		i++;
	}

	return (result);
}
