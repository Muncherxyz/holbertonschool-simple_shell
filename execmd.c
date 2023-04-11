#include "shell.h"
/**
 *
 *
 **/
void execmd(char **argv){
    
  pid_t pid = fork();

    if (pid == -1) {
        perror("Error: fork");
        exit(1);
    }
    else if (pid == 0) {
        /* child process */
        if (execve(argv[0], argv, NULL) == -1) {
            perror("Error: execve");
            exit(1);
        }
    }
    else {
        /* parent process */
        int status;
        if (waitpid(pid, &status, 0) == -1) {
            perror("Error: waitpid");
            exit(1);
        }
    }
}
