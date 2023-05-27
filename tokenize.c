#include "shell.h"

#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
        int exitcheck;

        if (info->argv[1])  /* If there is an exit arguement */
        {
                exitcheck = _erratoi(info->argv[1]);
                if (exitcheck == -1)
                {
                        info->status = 2;
                        print_error(info, "Illegal number: ");
                        _eputs(info->argv[1]);
                        _eputchar('\n');
                        return (1);
                }
                info->err_num = _erratoi(info->argv[1]);
                return (-2);
        }
        info->err_num = -1;
        return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
        char *s, *dir, buffer[1024];
        int chdir_ret;

        s = getcwd(buffer, 1024);
        if (!s)
                _puts("TODO: >>getcwd failure emsg here<<\n");
        if (!info->argv[1])
        {
                dir = _getenv(info, "HOME=");
                if (!dir)
                        chdir_ret = /* TODO: what should this be? */
                                chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
                else
                        chdir_ret = chdir(dir);
        }
        else if (_strcmp(info->argv[1], "-") == 0)
        {
                if (!_getenv(info, "OLDPWD="))
                {
                        _puts(s);
                        _putchar('\n');
                        return (1);
                }
                _puts(_getenv(info, "OLDPWD=")), _putchar('\n');
                chdir_ret = /* TODO: what should this be? */
                        chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
        }
        else
                chdir_ret = chdir(info->argv[1]);
        if (chdir_ret == -1)
        {
                print_error(info, "can't cd to ");
                _eputs(info->argv[1]), _eputchar('\n');
        }
        else
        {
                _setenv(info, "OLDPWD", _getenv(info, "PWD="));
                _setenv(info, "PWD", getcwd(buffer, 1024));
        }
        return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
        char **arg_array;

        arg_array = info->argv;
        _puts("help call works. Function not yet implemented \n");
        if (0)
                _puts(*arg_array); /* temp att_unused workaround */
        return (0);
}

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
