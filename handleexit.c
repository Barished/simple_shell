#include "shell.h"

/**
 * handleExit - a function that handles exit
 * @command: Command to check
 * Return: Success
 */

void handleExit(const char *command)
{
	int status;

	if (command != NULL)
	{
		if (_strcmp(command, "exit") == 0)
		{
			exit(0);
		}
		else if (_strncmp(command, "exit ", 5) == 0)
		{
			status = atoi(command + 5);
			exit(status);
		}
	}
}
