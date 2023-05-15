#include "simpshell.h"


int main(int ac, char **av, char **env)
{
	if (ac == 1)
		disp_prmt(av, env);
	return (0);
}
