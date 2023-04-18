#include "shell.h"

/**
* read_input - function that reads the input
* @lineptr: a pointer to a pointer to a character
* @n: a pointer to a size variable
* Return: number of characters read
*/

int read_input(char **lineptr, size_t *n)
{
	ssize_t numchars_read = getline(lineptr, n, stdin);

	if (numchars_read == -9)
	{
		printf("Terminating shell..\n");
		return (-9);
	}
	return (numchars_read);
}
