#include "shell.h"

/**
 * no_nl - removes the new line with the NULL character
 * @l: the line
 * Return: nothing
 */
void nwdl(char *l)
{

        int i = 0;

        while (l[i])
        {
                if (l[i] == '\n')
                {
                        l[i] = '\0';
                        return;
                }

                i++;
        }
}


/**
 * special_char - if the user types control d, it exits the shell and handles
 * the error when the user keeps on tabbing, it carries out the command
 * @bytes: the number of bytes read in from the user input
 * @buffer: the buffer
 * @ex_st: the exit status
 * Return: Always (0) for succcess
 */
int  special_char(char *buffer, ssize_t bytes, int *ex_st)
{
        int i = 0;

        if (bytes == EOF && isatty(STDIN_FILENO) == 1)
        {
                _putchar('\n');
                free(buffer);
                exit(*ex_st);
        }

        if (bytes == EOF && isatty(STDIN_FILENO) == 0)
        {
                free(buffer);
                exit(*ex_st);
        }

        if (_strcmp(buffer, "\n") == 0)
        {
                *ex_st = 0;
                return (127);
        }

        while (buffer[i] != '\n')
        {
                if (buffer[i] != ' ' && buffer[i] != '\t')
                        return (0);

                ++i;
        }

        *ex_st = 0;
        return (127);
}
