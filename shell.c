#include "shell.h"
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


int main(int ac, char **argv)\
{
	#include "shell.h"

int main(int argc, char **argv)
{
    char *prompt = "$ ";
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t numchars_read;
    const char *delim = " \n";
    char **tokens = NULL;
    int i;

    (void)argc, (void)argv;

    while (1)
    {
        printf("%s", prompt);

        numchars_read = getline(&lineptr, &n, stdin);

        if (numchars_read == -1)
        {
            printf("Terminating shell..\n");
            break;
        }

        /* Tokenize the input */
        int num_of_tokens = 0;
        char *token = strtok(lineptr, delim);
        while (token != NULL)
        {
            num_of_tokens++;
            token = strtok(NULL, delim);
        }

        /* Allocate memory for an array of tokens */
        tokens = malloc(sizeof(char *) * (num_of_tokens + 1));
        if (tokens == NULL)
        {
            perror("Memory allocation error");
            break;
        }

        /* Populate the array of tokens */
        token = strtok(lineptr, delim);
        for (i = 0; token != NULL; i++)
        {
            tokens[i] = strdup(token);
            token = strtok(NULL, delim);
        }
        tokens[i] = NULL;

        /* Execute the command */
        execute_command(tokens);

        /* Free memory */
        free_tokens(tokens);
        free(lineptr);
        lineptr = NULL;
    }

    return 0;
}
