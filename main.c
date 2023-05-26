#include "shell.h"

/**
 * main - entry point of the simple shell program.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0 if success
 */
int main(int argc, char **argv)
{
	char *alllineptr;
	size_t inputsize;
	int inputcounter;

	(void)argc;
	inputcounter = 0;
	signal(SIGINT, _ignoreSignal);
	do {
		inputcounter++;
		alllineptr = NULL;
		inputsize = 0;
		_customPrompt(alllineptr, inputsize, inputcounter, argv);

	} while (1);

	return (0);
}
