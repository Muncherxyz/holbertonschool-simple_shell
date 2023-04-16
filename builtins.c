#include "shell.h"
/**
 * builtfunc - function that implements the exit builtin
 * @buf: buffer
 * @args: the parsed arguments
 * @env: the environment
 * @exstat: exit status
 * Return: void
 */
void builtfunc(char **buf, char **args, char **env, int *exstat)
{
  if (_strcmp(args[0], "exit") == 0)
    {
      if (args[1] == NULL)
	{
	  *exstat = 0;
	}
      free(buf);
      free(args);
      free(env);

      fclose(stdin);
      fclose(stdout);
      fclose(stderr);

      exit(*exstat);
    }
}
