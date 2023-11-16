#include "myshell.h"

/**
 * usable_size - returns the size of a memory block
 * @ptr: pointer to the memory block
 * Return: size of the memory block
 */
size_t usable_size(const void *ptr)
{
size_t *size = (size_t *)ptr - 1;
return (*size);
}

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
char __attribute__((unused)) *orig_src = src;
char __attribute__((unused)) *orig_dst = dst;

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
_strcpy(dst, var_value);
}
return (src);
}

/**
 * my_realloc - reallocates a memory block
 * @ptr: pointer to the memory block
 * @size: size of the memory block
 * Return: void
 */
void *my_realloc(void *ptr, size_t size)
{
void *new_p;
size_t old_size, copying_size, i;
if (ptr == NULL)
{
return (malloc(size));
}
if (size == 0)
{
free(ptr);
return (NULL);
}
new_p = malloc(size);
if (new_p == NULL)
{
return (NULL);
}
old_size = usable_size(ptr);
copying_size = (old_size < size) ? old_size : size;
for (i = 0; i < copying_size; ++i)
{
((char *)new_p)[i] = ((char *)ptr)[i];
}
free(ptr);
return (new_p);
}
