#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFSIZE 1024
#define MAX_ARGS 16
#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

extern char** environ;

void handleExit(const char* command);
char *read_line(void);
int tokenize(const char* input, char** tokens, const char *delimiter);
int execute(char **args);
void handleCD(const char *directory);
void print_environment(char **env);
char* _getenv(const char* name);
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);
int _strncmp(const char *str1, const char *str2, size_t n);
void allocate_token(char **tokens, int count);
void handleCDHomeDirectory(const char *home_directory);
void handleCDPreviousDirectory(const char *previous_directory);
void handleCDDirectory(const char *directory);
void handleSetEnv(const char *variable, const char *value, int overwrite);
void handleUnsetEnv(const char *variable);


#endif /*SHELL_H*/
