#include "shell.h"

/**
 * main - the main program
 * @ac: Argument count
 * @av: Argument variable
 * @env: Environment variable
 * Return: Success
 */

int main(int ac, char **av, char **env)
{
	while (1)
	{
		if (ac == 1)
			disp_prmt(av, env);
	}
	return (0);
}
