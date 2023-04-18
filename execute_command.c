#include "shell.h"
/**
* execute_command - a function to execute the command
* @args: a pointer to an array of strings
* Return: nothing
*/
int execute_command(char **args)
{
	pid_t c_pid = fork();

	if (c_pid != 0)
		wait(NULL);
	if (c_pid == 0)
	{
		execve(args[0], args, NULL);
		perror("ERROR");
		exit(1);
	}
	return (0);
}
