#include "myshell.h"

/**
 * shells - Inactive shell
 * Return: Always 0
 */
int shells(void)
{
char __attribute__((unused)) *args[100], *input = NULL;
char __attribute__((unused)) path[100];
size_t l = 0;
ssize_t __attribute__((unused)) a, r;
pid_t __attribute__((unused)) pid;
int __attribute__((unused)) ex;
while (1)
{
a = write(STDOUT_FILENO, "$ ", 2);
r = _getsline(&input, &l, stdin);
if (r == -1)
{
perror("getline:");
free(input);
exit(-1);
}
_strtok(input, "\n");
args[0] = input;
args[1] = NULL;
fork_wait_execute(args);
}
free(input);
return (EXIT_SUCCESS);
}

/**
 * fork_wait_execute - Forks a child process and waits for it to finish
 * @args:arguments
 * Return: Always 0 (success)
 */
int fork_wait_execute(char **args)
{
pid_t pid;
int ex;
pid = fork();
if (pid == 0)
{
ex = execve(args[0], args, NULL);
if (ex == -1)
{
perror("execve:");
exit(-1);
}
}
else if (pid > 0)
{
wait(NULL);
}
else
{
perror("Error:");
exit(-1);
}
return (EXIT_SUCCESS);
}
