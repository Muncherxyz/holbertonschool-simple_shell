#include "shell.h"

int pathfinder(char *first, char **input, char **env, int *ex_st)
{
    int i, j;
    char *temp, *left, *right;
    char *new = NULL;
    char **path_dirs = '\0';

    for (i = 0; env[i] != NULL; i++)
    {
        if (_strcmp(env[i], "PATH=") == 0)
        {
            
            temp = _strdup(env[i] + 5);
            for (j = 0, left = temp; ; j++, left = NULL)
            {
                right = strtok(left, ":");
                if (right == NULL)
                    break;
                path_dirs = realloc(path_dirs, (j + 1) * sizeof(char *));
                path_dirs[j] = right;
            }
            free(temp);

      
            for (j = 0; j < path_dirs; j++)
            {
                new = pathstr(path_dirs[j], first);
                if (access(new, X_OK) == 0)
                {
                    if (fork() == 0)
                        execve(new, input, NULL);
                    else
                        wait(NULL);
                    *ex_st = 0;
                    free(new);
                    free(path_dirs);
                    return 0;
                }
                free(new);
            }

            free(path_dirs);
            break;
        }
    }

    return 2;
}
