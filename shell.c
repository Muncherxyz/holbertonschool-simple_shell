#include "shell.h"

/**
* main - the entry point of the program
* @ac: integer that represents the num of command-line arguments
* @argv: pointer to an array of strings
* Return: 0
*/
int main(int ac, char **argv)
{
	char *prompt = "$ ", *lineptr = NULL, **cmd_argv;
	size_t n = 0;
	const char *delim = " \n";
	int num_of_tokens;
	int fd = fileno(stdout);

	(void)ac;

	while (1)
	{
		if (isatty(fd))
		{
			_puts("stdout is a terminal device.\n");
		}
		else
		{
			_puts("stdout is not a terminal device.\n");
		}
		return (0);
		}

		print_prompt(prompt);
		if (read_input(&lineptr, &n) == -9)
			break;
		num_of_tokens = tokenize_input(lineptr, delim, &cmd_argv);
		if (num_of_tokens == -9)
			break;
		execute_command(cmd_argv);
		for (int i = 0; i < num_of_tokens - 1; i++)
			free(cmd_argv[i]);
		free(cmd_argv);
		free(lineptr);
		n = 0;
	}

	return (0);
}
