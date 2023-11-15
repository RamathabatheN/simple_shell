#include "myshell.h"

/**
 * main - our shell
 * @argc: number of arguments
 * @argv: arguments
 * @envp: environment variables
 * Return: Always 0
 */
int main(int __attribute__((unused)) argc, char __attribute__((unused)) *argv[]
, char __attribute__((unused)) *envp[])
{
while (1)
{
char *input = NULL;
size_t len = 0;
ssize_t __attribute__((unused)) a;

a = write(1, "$ ", 2);
if (_getsline(&input, &len, stdin) == -1)
{
perror("getline");
exit(-1);
}
parse_execute(input, environ);
free(input);
}
return (0);
}
