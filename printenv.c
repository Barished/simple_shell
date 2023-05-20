#include "shell.h"

/**
 * print_environment - a function to print the current environment
 * @env: Enviroment variable
 * Return: Success
 */

void print_environment(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
