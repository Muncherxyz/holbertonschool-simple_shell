#include "shell.h"

int main(int argc, char **argv, char **env)
{
        char *prompt = "($)";
        char *line = NULL;
        char **args = NULL;
        int i = 0, status = 0, arg_num = 0;
        static int exit_stat, count;
        size_t len = 0;
        ssize_t read = 0;
        (void)argc, (void)**argv;

        while (1)
        {

                if (isatty(STDIN_FILENO))
                        write(STDOUT_FILENO, prompt, 6);


                read = getline(&line, &len, stdin);


                if (special_char(line, read, &exit_stat) == 127)
                        continue;


                nwdl(line);


                args = parser(line);


                for (i = 0; args[i]; i++)
                        arg_num++;


                builtins(line, args, env, &exit_stat);


                status = pathfinder(args[0], args, env, &exit_stat);


                execute_command(status, args, &exit_stat, &count);


                fflush(stdin);
        }
       free(line);

        return 0;
}
