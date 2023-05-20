#include "shell.h"

/**
 * handleCD - a function the handle the cd command
 * @directory: Directory to work with
 * Return: Success
 */

void handleCD(const char *directory)
{
	char *home_directory = getenv("HOME");
	char *previous_directory = getenv("PWD");
	char cwd[1024];

	if (directory == NULL)
	{
		if (home_directory == NULL)
		{
			fprintf(stderr, "cd: No home directory found.\n");
			return;
		}
		if (chdir(home_directory) != 0)
		{
			perror("cd");
		}
	}
	else if (strcmp(directory, "-") == 0)
	{
		if (previous_directory == NULL)
		{
			fprintf(stderr, "No previous directory available.\n");
			return;
		}
		if (chdir(previous_directory) != 0)
		{
			perror("cd");
		}
	}
	else
	{
		if (chdir(directory) != 0)
		{
			perror("cd");
		}
	}


	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		setenv("PWD", cwd, 1);
	}
	else
	{
		perror("getcwd");
	}
}
