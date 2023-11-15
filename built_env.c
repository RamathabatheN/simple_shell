#include "myshell.h"

/**
 * envr - prints the environment variables
 * @command: input string
 * Return: a
 */
int envr(char **command)
{
unsigned int a;
ssize_t e, f;
for (a = 0; environ[a] != NULL; a++)
{
e = write(1, environ[a], _strlen(environ[a]));
f = write(1, "\n", 1);
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
ssize_t q;
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
return (0);
}

/**
 * unset_env - unsets the environment variables
 * @command: input string
 * Return: Always 0
 */
int unset_env(char **command)
{
ssize_t q;
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
return (0);
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
char *src, *dst, var_name[128], *var_value;
int var_idx;
char *output = malloc(_strlen(input) + 1);
if (output == NULL)
{
perror("malloc");
exit(1);
}
src = input;
dst = output;
while (*src)
{
if (src[0] == '$' && src[1] != '\0')
{
src++;
if (src[0] == '?')
{
my_sprintf(dst, "%d", WEXITSTATUS(status));
dst += _strlen(dst);
src++;
}
else if (src[0] == '$')
{
my_sprintf(dst, "%d", getpid());
dst += _strlen(dst);
src++;
}
else
{
var_idx = 0;
while (*src && *src != ' ' && *src != '\t' && *src != '\n')
{
var_name[var_idx++] = *src;
src++;
}
var_name[var_idx] = '\0';
var_value = m_getenv(var_name);
if (var_value != NULL)
{
_strcpy(dst, var_value);
dst += _strlen(var_value);
}
}
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
