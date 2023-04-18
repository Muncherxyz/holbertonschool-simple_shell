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
/*extern char **environ;*/
extern char **environ; 
int main(int argc, char **argv);

void execmd(char **argv);
char *get_location(char *command);
/* use your own _str files*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, int n);
char *string_nconcat(char *s1, char *s2, unsigned int n);
char *_strstr(char *haystack, char *needle);
char *_getline(void);

void print_prompt(char *prompt);
int read_input(char **lineptr, size_t *n);
int tokenize_input(char *lineptr, const char *delim, char ***argv);
int execute_command(char **argv);

void builtfunc(char **buf, char **args, char **env, int *exstat);
/* add _putchar and _puts */
int _putchar(char c);
void _puts(char *s);

#endif
