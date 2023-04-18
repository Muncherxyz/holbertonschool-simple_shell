#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int pathfinder(char *first, char **input, char **env, int *ex_st);


int printenv(char **env, int *ex_st);


void builtins(char *line, char **args, char **env, int *ex_st);
void execute_command(int status, char **args, int *ex_st, int *tal);


int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);


int _putchar(char c);
void print_str(char *s);
char *pathstr(char *right, char *first);
char **parser(char *l);
void print_int(int *tal);


void nwdl(char *l);
int special_char(char *buffer, ssize_t bytes, int *ex_st);

#endif
