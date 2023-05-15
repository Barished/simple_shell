#ifndef TASKS_H
#define TASKS_H



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFSIZE 1024
#define MAX_ARGS 16

void disp_prmt(char **av, char **env);



#endif /*TASKS_H*/
