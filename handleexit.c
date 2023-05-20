#include "shell.h"

/**
 * handleExit - a function that handles exit
 * Return: Success
 */

void handleExit(const char* command)
{
	if (command != NULL)
	{
		if (strcmp(command, "exit") == 0)
		{
			exit(0);
		}
	}
}
