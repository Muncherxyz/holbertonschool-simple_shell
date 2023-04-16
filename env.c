#include "shell.h"


int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* _puts - custom function prints a string
* @s: pointer to the string
* Return: void
*/

void _puts(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}

/**
* envbuiltin - function that prints current environment
* @environ: double pointer to list of env variables
* Return: 0 on success
*/
void envbuiltin(char **environ)
{
	int i;

	i = 0;
	while (environ[i])
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
}
