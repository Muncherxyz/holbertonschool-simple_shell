#include "shell.h"
/**
* tokenize_input - this function tokenizes the user input
* @lineptr: a pointer to the address of a character
* @delim: a pointer to the address of a delimeter
* @argv: a pointer to a pointer to a pointer to a character
* Return: number of tokens
*/
int tokenize_input(char *lineptr, const char *delim, char ***argv)
{
	int num_of_tokens = 0;

	char *token = strtok(lineptr, delim);

	while (token != NULL)
	{
		num_of_tokens++;
		token = strtok(NULL, delim);
	}
	num_of_tokens++;

	*argv = malloc(sizeof(char *) * num_of_tokens);
	if (*argv == NULL)
	{
		perror("Memory allocation error");
		return (-9);
	}

	char *saveptr = NULL;

	token = strtok_r(lineptr, delim, &saveptr);
	for (int i = 0; i < num_of_tokens - 1; i++)
	{
		(*argv)[i] = strdup(token);
		token = strtok_r(NULL, delim, &saveptr);
	}
	(*argv)[num_of_tokens - 1] = NULL;

	return (num_of_tokens);
}
