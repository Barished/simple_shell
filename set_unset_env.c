#include "shell.h"

/**
 * handleSetEnv - a function to handle the setenv command
 * @variable: The environment variable to set
 * @value: The value to assign to the environment variable
 * @overwrite: The number of charater to write
 * Return: Success
 */

void handleSetEnv(const char *variable, const char *value, int overwrite)
{
	if (variable == NULL || value == NULL)
	{
		fprintf(stderr, "setenv: Missing argument.\n");
		return;
	}

	if (setenv(variable, value, overwrite) != 0)
	{
		perror("setenv");
	}
}

/**
 * handleUnsetEnv - a function to handle the unsetenv command
 * @variable: The environment variable to unset
 * Return: Success
 */

void handleUnsetEnv(const char *variable)
{
	if (variable == NULL)
	{
		fprintf(stderr, "unsetenv: Missing argument.\n");
		return;
	}

	if (unsetenv(variable) != 0)
	{
		perror("unsetenv");
	}
}
