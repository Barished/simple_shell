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
#define BUFFER_SIZE 1024
#define MAX_ARGS 16
#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

#define MAX_ALIASES 100
#define MAX_ALIAS_LENGTH 100

#define MAX_PATH_LENGTH 1024

typedef struct AliasNode {
    char *name;
    char *value;
    struct AliasNode *next;
} AliasNode;

extern AliasNode *aliasList;

extern char** environ;
char current_directory[1024];

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
int customAtoi(const char *str);
int execute_commands(char **commands);
void printAliases(AliasNode *aliasList);
void printAlias(const char *name, AliasNode *aliasList);
void setAlias(const char *name, const char *value, AliasNode **aliasList);
void handleAlias(char **args);
char *_strcpy(char *destination, const char *source);
void freeAliases(AliasNode **aliasList);
int process_command(char **args, char **env, int count, char **toks, char *lin);
void free_tokens(int token_count, char **tokens);
void allocate_tokens(int token_count, char ***tokens);
void print_prompt(void);
void execute_child(char **args);

#endif /*SHELL_H*/
