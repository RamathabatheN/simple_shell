#include "myshell.h"

/**
 * h_dollar_sign - Handles the cases when a dollar sign is encountered
 * @src: input string after encountering '$'
 * @dst: destination string
 * @envp: environment variables
 * @status: exit status
 * Return: updated src
 */
char *h_dollar_sign(char *src, char *dst, char **envp, int status)
{
char __attribute__((unused)) *og_src = src;
char __attribute__((unused)) *og_dst = dst;

if (src[0] == '?')
{
src++;
my_sprintf(dst, "%d", WEXITSTATUS(status));
dst += _strlen(dst);
}
else if (src[0] == '$')
{
src++;
my_sprintf(dst, "%d", getpid());
dst += _strlen(dst);
}
else
{
src = h_var_name(src, dst, envp);
dst += _strlen(dst);
}
return (src);
}

/**
 * h_var_name - Handles the variable name after encountering '$'
 * @src: input string after encountering '$'
 * @dst: destination string
 * @envp: environment variables
 * Return: updated src
 */
char *h_var_name(char *src, char *dst, char __attribute__((unused)) **envp)
{
int var_idx = 0;
char variable_name[128];
char *var_value;
while (*src && *src != ' ' && *src != '\t' && *src != '\n')
{
variable_name[var_idx++] = *src;
src++;
}
variable_name[var_idx] = '\0';
var_value = m_getenv(variable_name);
if (var_value != NULL)
{
_strcpy(dst, var_value, sizeof(dst));
}
return (src);
}
