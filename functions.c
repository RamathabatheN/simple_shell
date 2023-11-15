#include "myshell.h"

/**
 * _strcat - concatenates two strings
 * @dest: input string
 * @src: input string
 * Return:dest
 */
char *_strcat(char *dest, char *src)
{
int j = 0, b = 0;
while (dest[j] != '\0')
{
j++;
}
while (src[b] != '\0')
{
dest[j] = src[b];
j++;
b++;
}
dest[j] = '\0';
return (dest);
}

/**
 * _strcpy - copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: copied string
 */
char *_strcpy(char *dest, char *src)
{
int a = 0;
int j;

while (*(src + a) != '\0')
{
a++;
}
for (j = 0 ; j < a ; j++)
{
dest[j] = src[j];
}
dest[a] = '\0';
return (dest);
}


/**
 * _strtok - removes tokens from string
 * @s: input string
 * @delim: delimiter
 * Return: string without tokens
 */
char *_strtok(char *s, const char *delim)
{
static char *follow = NULL;
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
return (char *)s;
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

