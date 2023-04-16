#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 1024

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>



extern char **environ;

#define _GNU_SOURCE

int main(int argc, char **argv);

void envbuiltin(char **environ);
char *get_env(char *name);
/* use your own _str files*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, int n);
char *string_nconcat(char *s1, char *s2, unsigned int n);
char *_strstr(char *haystack, char *needle);

void builtfunc(char **buf, char **args, char **env, int *exstat);

void double_free(char **array);
/* add _putchar and _puts */
int _putchar(char c);
void _puts(char *s);

#endif
