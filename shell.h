#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#define PROMPT "> "

/**
 * struct built_cmd - Defines the builtins functions.
 * @built_in: name of build in command.
 * @fptr: pointer to uiltin function.
 */
typedef struct built_cmd
{
	char *built_in;
	void (*fptr)(char *);
} built_t;

int status_code;
extern char **environ;

unsigned int _strlen(char *string);
char *_strdup(char *string);
int _strcmp(char *str1, char *str2);
int _strncmp(char *str1, char *str2, int num);
char *_strcpy(char *destination, char *source);
char *_strcat(char *destination, char *source);
void _customPrompt(char *alllineptr, size_t buffsize, int count, char **argv);
int calcTokencmd(char *alllineptr, const char *delimeter);
void (*_checkbuiltin(char *function))(char *s);
char **_tokenParsing(int token, char *alllineptr, const char *delimeter);
char *_getenv(char *key);
void _exit_more(char *alllineptr);
void _execute(char **alllinecmd, char *linepointer, int cmdcount, char **argv);
void _envir(char *alllineptr);
int _customAtoi(char *str);
int _built(char **alllinecmd, char *linepointer);
void _ignoreSignal(int signal);
char **_tokenPath(char *s);
char *_executePath(char **token, char *command);
void _freePointer(char **s);
void _exitGetline(char *alllineptr);
void _errorExecute(char *argv, int count, char *command);
void _printError(char *argv, int count, char *command);
char *_cmd_path(char *cmd_path, char *command);
char *_execPath(char *command);
char *update_add_env(char *key, char *value);
int _putchar(char ch);
void _puts(char *s);
int _printint(int nb);
int cd_setenv(char *key, char *value, int overwrite);
void _cd(char *lineptr);
int cd_abspath(char *path);
void _setenv(char *lineptr);
int cd_home(void);
int cd_toggle(void);
ssize_t _getline(char **lineptr, ssize_t size, FILE *stream);
void status_exec(char **argv);
char *_strchr(char *str, char c);
int cd_cwd(void);

#endif /* SHELL_H */
