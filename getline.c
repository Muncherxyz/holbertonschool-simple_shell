#include "shell.h"
/**
* _getline - gets command from line in stdin
* Return: command
*/
char *_getline(void)
{
	char *line = NULL;
	size_t input_len = 0;

	if (isatty(STDIN_FILENO) == 1)
		_putchar("($) ");
	if (getline(&line, &input_len, stdin) < 0)
	{
		if (isatty(STDIN_FILENO) == 1)
			_putchar("\n");
		free(line);
		exit(0);
	}
	return (line);
}
