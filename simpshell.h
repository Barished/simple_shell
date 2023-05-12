#ifndef SIMPSHELL_H
#define SIMPSHELL_H

char *read_line(void);
char **tokenize(char *line);
int execute(char **args);



#endif /*SIMPSHELL_H*/
