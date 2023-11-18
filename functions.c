#include "myshell.h"

/**
 * _strtok - removes tokens from string
 * @s: input string
 * @delim: delimiter
 * Return: string without tokens
 */
char *_strtok(char *s, const char *delim)
{
static char *follow;
char *token;

if (s != NULL)
{
follow = s;
}
if (follow == NULL || delim == NULL || *follow == '\0')
{
return (NULL);
}
while (_strchr(delim, *follow) != NULL)
{
follow++;
}
if (*follow == '\0')
{
return (NULL);
}
token = follow;
while (*follow && _strchr(delim, *follow) == NULL)
{
follow++;
}
if (*follow != '\0')
{
*follow = '\0';
follow++;
}
return (token);
}


/**
 * _strchr - locates a character in a string
 * @s:input
 * @c:input
 * Return: Always 0 (Success)
 */
char *_strchr(const char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
{
return ((char *)s);
}
s++;
}
return (*s == c ? (char *)s : NULL);
}

/**
 * _strlen - returns the length of a string
 * @s:input string
 * Return: string length
 */
size_t _strlen(char *s)
{
size_t j;
for (j = 0; s[j]; j++)
{
}
return (j);
}

/**
 * _strcpy - copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * @dest_size: size of dest
 * Return: copied string
 */
void _strcpy(char *dest, const char *src, size_t dest_size)
{
ssize_t __attribute__((unused)) a;
size_t i;
if (dest == NULL || src == NULL || dest_size == 0)
{
a = write(STDERR_FILENO, "Invalid input in safe_strcpy\n", 29);
return;
}
for (i = 0; i < dest_size - 1 && src[i] != '\0'; ++i)
{
dest[i] = src[i];
}
dest[i] = '\0';
}

/**
 * _strcat - concatenates two strings
 * @dest: input string
 * @src: input string
 * @dest_size: size of dest
 * Return:dest
 */
void _strcat(char *dest, const char *src, size_t dest_size)
{
ssize_t __attribute__((unused)) a;
size_t i, dest_len;
if (dest == NULL || src == NULL || dest_size == 0)
{
a = write(STDERR_FILENO, "Invalid input in safe_strcat\n", 29);
return;
}
dest_len = strlen(dest);
for (i = 0; i < dest_size - 1 - dest_len && src[i] != '\0'; ++i)
{
dest[dest_len + i] = src[i];
}
dest[dest_len + i] = '\0';
}
