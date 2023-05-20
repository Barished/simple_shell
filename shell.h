#ifndef SHELL_H
#define SHELL_H



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFSIZE 1024
#define MAX_ARGS 16
#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100


void handleExit(const char* command);
char *read_line(void);
int tokenize(const char* input, char** tokens, const char *delimiter);
int execute(char **args);

#endif /*SHELL_H*/
