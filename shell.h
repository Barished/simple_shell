#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @s: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *s;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

ssize_t buffread(info_t *info, char *buf, size_t *i);
ssize_t inputbuff(info_t *info, char **buf, size_t *len);


int shell(info_t *, char **);
int fbuiltin(info_t *);
void fcmd(info_t *);
void fork_cmd(info_t *);

int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);



int loophsh(char **);
int _satoi(char *s);
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int pstring(char *str, int fd);

int _strlen(char *);
int _strcmp(char *, char *);
char *startwith(const char *, const char *);
char *_strcat(char *, char *);

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

char **strtow(char *, char *);
char **strtow2(char *, char);

char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

int _pfree(void **);

int interactif(info_t *);
int _isdelim(char, char *);
int _isalpha(int);
int _atoi(char *);

int _erratoi(char *);
void _printerr(info_t *, char *);
int _printdeci(int, int);
char *_convno(long int, int, int);
void _delcomment(char *);

int my_exit(info_t *);
int my_cd(info_t *);
int my_help(info_t *);

int _listHistory(info_t *);
int _myalias(info_t *);

ssize_t _getinput(info_t *);
int _getline(info_t *, char **, size_t *);
void cblock(int);

void _infoClear(info_t *);
void _infoSet(info_t *, char **);
void _infoFree(info_t *, int);


char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int set_env(info_t *);
int unset_env(info_t *);
int populate_env_list(info_t *);

char *get_env(info_t *, const char *);
int curr_env(info_t *);
int set_env(info_t *);
int unset_env(info_t *);
int show_env(info_t *);


char **getEnv(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

char *_historyFile(info_t *info);
int historyWrite(info_t *info);
int read_history(info_t *info);
int buildHistory(info_t *info, char *buf, int linecount);
int renumberHis(info_t *info);

list_t *addNode(list_t **, const char *, int);
list_t *addEndnode(list_t **, const char *, int);
size_t printstrList(const list_t *);
size_t plist(const list_t *h);
int _indexdelnode(list_t **, unsigned int);
void _freeList(list_t **);

size_t llength(const list_t *);
char **toString(list_t *);
size_t listPrint(const list_t *);
list_t *startNode(list_t *, char *, char);
ssize_t _nodeIndex(list_t *, list_t *);


int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif
