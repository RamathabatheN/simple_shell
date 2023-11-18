#include "myshell.h"

/**
 * envr - prints the environment variables
 * @command: input string
 * Return: a
 */
int envr(char __attribute__((unused)) **command)
{
unsigned int a = 0;
ssize_t __attribute__((unused)) e, __attribute__((unused)) f;
ssize_t __attribute__((unused)) g;
if (strcmp(command[0], "env") == 0)
{
for (a = 0; environ[a] != NULL; a++)
{
e = write(STDOUT_FILENO, environ[a], strlen(environ[a]));
f = write(STDOUT_FILENO, "\n", 1);
}
}
else
{
g = write(STDOUT_FILENO, "Invalid command\n", 16);
}
return (a);
}

/**
 * set_env - sets the environment variables
 * @command: input string
 * Return: Always 0
 */
int set_env(char **command)
{
ssize_t __attribute__((unused)) q;
if (command[1] == NULL || command[2] == NULL)
{
q = write(STDERR_FILENO, "Usage: setenv VARNAME VALUE\n", 28);
return (-1);
}
if (setenv(command[1], command[2], 1) != 0)
{
perror("setenv");
return (-1);
}
return (EXIT_SUCCESS);
}

/**
 * unset_env - unsets the environment variables
 * @command: input string
 * Return: Always 0
 */
int unset_env(char **command)
{
ssize_t __attribute__((unused)) q;
if (command[1] == NULL)
{
q = write(STDERR_FILENO, "Usage: unsetenv VARNAME\n", 24);
return (-1);
}
if (unsetenv(command[1]) != 0)
{
perror("unsetenv");
return (-1);
}
return (EXIT_SUCCESS);
}

/**
 * expand_env_vars - expands the environment variables in a string
 * @input: input string
 * @envp: environment variables
 * @status: exit status
 * Return: output
 */
char *expand_env_vars(char *input, char **envp, int status)
{
char *src, *dst;
char *output = malloc(_strlen(input) + 1);
if (output == NULL)
{
perror("malloc");
exit(-1);
}
src = input;
dst = output;
while (*src)
{
if (src[0] == '$' && src[1] != '\0')
{
src = h_dollar_sign(src + 1, dst, envp, status);
}
else
{
*dst = *src;
src++;
dst++;
}
}
*dst = '\0';
return (output);
}
