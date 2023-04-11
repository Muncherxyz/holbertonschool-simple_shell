#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define DELIM "\t\n"


int main(int argc, char **argv);

void execmd(char **argv);
char *get_location(char *command);
/* use your own _str files*/

void builtfunc(char **buf, char **args, char **env, int *exstat);
/* add _putchar and _puts */
#endif
