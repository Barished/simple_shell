#include "shell.h"

/**
 * handleCD - a function the handle the cd command
 * @directory: Directory to work with
 * Return: Success
 */

void handleCD(const char *directory)
{
	char *home_directory = _getenv("HOME");
	char *previous_directory = _getenv("PWD");

	if (directory == NULL)
	{
		handleCDHomeDirectory(home_directory);
	}
	else if (_strcmp(directory, "-") == 0)
	{
		handleCDPreviousDirectory(previous_directory);
	}
	else
	{
		handleCDDirectory(directory);
	}

	if (getcwd(current_directory, sizeof(current_directory)) != NULL)
	{
		handleSetEnv("PWD", current_directory, 1);
	}

	else
	{
		perror("getcwd");
	}
}

/**
 * handleCDHomeDirectory - helper function, handles cd with no directory arg
 * @home_directory: The home directory path
 * Return: Success
 */

void handleCDHomeDirectory(const char *home_directory)
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

/**
 * handleCDPreviousDirectory - helper function, handles cd with '-' argument
 * @previous_directory: The previous directory path
 * Return: Success
 */

void handleCDPreviousDirectory(const char *previous_directory)
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

/**
 * handleCDDirectory - function, handles cd with a specific directory argument
 * @directory: The directory path
 * Return: Success
 */

void handleCDDirectory(const char *directory)
{
	if (chdir(directory) != 0)
	{
		perror("cd");
	}
}
