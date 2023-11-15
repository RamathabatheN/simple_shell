#include "myshell.h"

/**
 * shells - our shell
 * Return: Always 0
 */
int shells(void)
{
char *args[100], *input = NULL, path[100];
size_t l = 0;
ssize_t a, r;
pid_t pid;
int ex;
while (1) 
{
a = write(1, "$ ", 2);
r = getline(&input, &l, stdin);
if (r == -1)
{
perror("getline:");
free(input);
exit(-1);
}
strtok(input, "\n");
args[0] = input;
args[1] = NULL;
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
exit(-3);
}
}
free(input);
return (0);
}
