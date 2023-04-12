# 0x17.c Simple Shell

## Description of Project
For this simple shell project, we are to create a simple shell interpreter. The shell program will read input from the user, parse the input to identify the command and its arguments, and then execute the command by creating a child process. The shell should be able to handle built-in commands as well as external commands. The program should produce output identical to the sh (/bin/sh) shell, including errors. However, when an error occurs, the program name should be the same as the argv[0] value. For example:

When using the sh shell, if an unknown command is entered, an error message is displayed with the name of the shell:
```
$ echo "qwerty" | /bin/sh

/bin/sh: 1: qwerty: not found
```

Similarly, when using your program "hsh", if an unknown command is entered, an error message should be displayed with the name of your program:
```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
```

Note that even if you specify the program location with an absolute or relative path, the error message should still display the correct program name:
```
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
```
## Instructions
Here are the instructions to compile and execute a shell program named hsh:

- Open your terminal and navigate to the directory where your shell program files are located.

- To compile the program, type gcc -Wall -Werror -Wextra -pedantic *.c -o hsh and press Enter.

- To execute commands in interactive mode, type ./hsh followed by the command you want to run. For example, to list the files in the current directory, type /bin/ls after the hsh prompt and press Enter. You can also exit the shell by typing exit.

- To execute commands in non-interactive mode, use the pipe (|) operator to send a command to hsh. For example, to list the files in the current directory, type echo "/bin/ls" | ./hsh and press Enter. 
![Simple Shell Flowchart](https://user-images.githubusercontent.com/118311759/231554941-bc873c54-1d42-45e1-a665-c0caa60d8325.png)
## Authors
**Kortlan Blocker** | Github - Muncherxyz https://github.com/Muncherxyz

**Dominick Keeling** | Github - DominickKeeling https://github.com/account



