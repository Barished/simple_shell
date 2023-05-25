#include "shell.h"

/**
* read_line - a function that reads input from the user
* Return: 0 on success
*/

char *read_line(void)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_index;
	static ssize_t bytes_read;
	char *line = NULL;
	size_t line_size = 0;

	while (1)
	{
		if (buffer_index >= (size_t)bytes_read)
		{
			bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buffer_index = 0;

			if (bytes_read <= 0)
				break;
		}

		if (buffer[buffer_index] == '\n')
		{
			line[line_size++] = '\0';
			buffer_index++;
			return (line);
		}

		line = realloc(line, line_size + 1);
		line[line_size++] = buffer[buffer_index++];
	}

	if (line != NULL)
	{
		free(line);
	}

	return (NULL);
}
