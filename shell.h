#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>
#include <sys/wait.h>

#define MAX_ARGS 16
#define BUFSIZE 1024


int tokenize(const char *input, char **tokens, const char *delimiter);
int execute(char **args);

#endif /*SHELL_H*/
