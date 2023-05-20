#include "shell.h"

/**
* read_line - a function that reads input from the user
* Return: 0 on success
*/

char *read_line(void)
{
	int bufsize = BUFSIZE;
	int position = 0;
	int line;
	char *buffer;

	buffer = malloc(sizeof(char) * bufsize);
	if (buffer == NULL)
	{
		return (NULL);
	}

	while (1)
	{
		line = getchar();
		if (line == EOF || line == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = line;
		}
		position++;

		if (position >= bufsize)
		{
			bufsize += BUFSIZE;
			buffer = realloc(buffer, bufsize * sizeof(char));
			if (buffer == NULL)
			{
				return (NULL);
			}
		}
	}
}
