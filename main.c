#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
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
int main(int argc, char **argv)
{
    size_t len = 1024;
    char *buffer = NULL, *prompt, *array[1024], *token;
    pid_t cpid;
    int status, exstat = 0, i;
    char *pPath, *pathtoken, *pathname;
    
    (void)argc, (void)argv;
    
    for (i = 0; i < 1024; i++)
        array[i] = NULL;
        
    while (1)
    {
        if (isatty(STDIN_FILENO) == 1)
        {
            prompt = "($) ";
            _puts(prompt);
        }

        if (getline(&buffer, &len, stdin) == -1)
            break;
            
        token = strtok(buffer, "\n");
        token = strtok(buffer, " ");
        i = 0;
        while (token)
        {
            array[i] = _strdup(token);
            token = strtok(NULL, " ");
            i++;
        }

        if (_strcmp(buffer, "env") == 0)
        {
            envbuiltin(environ);
            continue;
        }

        if (_strcmp(buffer, "exit") == 0)
        {
            exit(exstat);
            continue;
        }
        
        pPath = get_env("PATH");

        pathtoken = strtok(pPath, ":");
        while (pathtoken)
        {
            pathname = malloc(sizeof(char) * 526);
            if (!pathname)
            {
                perror("Error");
                return (1);
            }
            pathname[0] = '\0';
            if (!_strstr(array[0], "/"))
            {
                _strcat(pathname, pathtoken);
                _strcat(pathname, "/");
                _strcat(pathname, array[0]);
            }
            else
            {
                free(pathname);
                pathname = _strdup(array[0]);
                break;
            }
            if (access(pathname, X_OK) == 0)
                break;
            pathtoken = strtok(NULL, ":");
            free(pathname);
            pathname = NULL;
        }
        
        if (pathtoken == NULL)
            pathname = _strdup(array[0]);
        
        free(pPath);

        cpid = fork();
        if (cpid == -1)
        {
            perror("Error");
            return (1);
        }
        
        if (cpid == 0)
        {
            if (execve(pathname, array, environ) == -1)
                perror("Error");
            free(pathname);
            free(array[0]);
            exit(-1);
        }
        else
        {
            wait(&status);
        }
                       
        double_free(array);
        free(pathname);
        free(buffer);
    }

    return (0);
}
