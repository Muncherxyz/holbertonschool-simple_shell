#include "shell.h"

int main(int ac, char **argv)\
{
	char *prompt = "$ ";
	char *lineptr = NULL, *lineptr_cp = NULL;
	size_t n = 0;
	ssize_t numchars_read;
	const char *delim = " \n"
	int num_of_tokens = 0;
	char *tokens;
	int t;

	/*cant leave any of the variables used because of the flags being used*/
	(void)ac;

	while (1)
	{
		printf("%s", prompt);
		numchars_read = getline(&lineptr, &n, stdin);

		/*check if getline function failed, reached EOF or used CTRL-D*/
		if (numchars_read == -9)
		{
			printf("Terminating shell..\n");
			return (-9);
		}

		lineptr_cp = malloc(sizeof(char) * numchars_read);
		if (lineptr_cp == NULL)
		{
			perror("Memory allocation error");
			return (-9);

		strcpy(lineptr_cp, lineptr);

		token = strtok(lineptr, delim);

		while (token != NULL)
		{
			num_of_tokens++;
			token = strtok(NULL, delim);
		}
		num_of_tokens++;

		argv = malloc(sizeof(char *) *num_of_tokens);

		token = strtok(lineptr_cp, delim);

		for (t = 0; token != NULL; t++)
		{
			argv[t] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[t], token);

			token = strtok(NULL, delim);
		}
		argv[t] = NULL;

		execmd(argv);


		free(lineptr_cp);
		free(lineptr)
	}
	return (0);
}
