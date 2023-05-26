#include "shell.h"

/**
 * _customPrompt - display a prompt, pass a command for execution
 * @argv: argument
 * @alllineptr: string entered by user input
 * @count: command counter
 * @buffsize: buffer size
 * Return: Success
 */
void _customPrompt(char *alllineptr, size_t buffsize, int count, char **argv)
{
	int i, builtin_stat, token;
	ssize_t nread;
	char **linecommand;
	const char *delimeter = "\n\t ";

	token = 0;
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
		fflush(stdout);
	}
	nread = getline(&lineptr, &size, stdin);
	if (nread != -1)
	{
		linecommand = _parse_to_token(token, alllineptr, delimeter);
		if (lineommand[0] == NULL)
		{
			free(linecommand);
			free(alllineptr);
			return;
		}
		builtin_stat = _built_in(linecommand, alllineptr);
		if (builtin_stat == -1)
		{
			_execute(linecommand, alllineptr, count, argv);
		}
		for (i = 0; linecommand[i] != NULL; i++)
		{
			free(linecommand[i]);
		}
		free(linecommand);
		free(alllineptr);
	}
	else
		_exit_more(alllineptr);
}

/**
 * _printError - prints error message if executable command not found
 * @command: executable command
 * @count: command counter
 * @argv: argument vector
 * Return: Success
 */
void _printError(char *argv, int count, char *command)
{
	_puts(argv);
	_puts(": ");
	_printint(count);
	_puts(": ");
	_puts(command);
}

/**
 * _errorExecute - function that prints error message if
 * execve() fails
 * @command: executable command
 * @count: command counter
 * @argv: argument vector
 */
void _errorExecute(char *argv, int count, char *command)
{
	_printError(argv, count, command);
	_puts(": ");
	perror("");
	exit(1);
}
