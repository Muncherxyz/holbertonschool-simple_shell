#include "shell.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * get_env - gets environment for path
 * @name: const char
 * Return: NULL
 */

char *get_env(char *name)
{
	int i;
	char *pathvalue;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, 4) == 0)
		{
			pathvalue = _strdup(&environ[i][5]);
			return (pathvalue);
		}
	}
	return (NULL);
}
