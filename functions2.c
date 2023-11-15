#include "myshell.h"

/**
 * _getsline - reads a line from the keyboard
 * @line: pointer to the buffer to store the line
 * @n: size of the buffer
 * @stream: stream to read from
 * Return: the number of characters read
 */
ssize_t _getsline(char **line, size_t *n, FILE *stream)
{
int c;
char *new_line;
size_t a = 0, new_size;
if (line == NULL || n == NULL || stream == NULL)
{
return (-1);
}

if (*line == NULL)
{
*line = (char *)malloc(128);
if (*line == NULL)
{
return (-1);
}
*n = 128;
}
while ((c = _fgetc(stream)) != EOF)
{
if (a >= *n - 1)
{
new_size = *n * 2;
new_line = (char *)realloc(*line, new_size);
if (new_line == NULL)
{
return (-1);
}
*line = new_line;
*n = new_size;
}
(*line)[a] = (char)c;
a++;
if (c == '\n')
{
break;
}
}
(*line)[a] = '\0';
if (a == 0)
{
return (-1);
}
return (a);
}


/**
 * _putchar - writes the character a to stdout
 * @c: The character to print
 * Return: On success 1. or -1 on error
 */
int _putchar(char a)
{
return (write(1, &a, 1));
}

/**
 * _strcmp - compare string values
 * @s1: input string
 * @s2: input string
 *
 * Return: s1[a] - s2[a]
 */
int _strcmp(char *s1, char *s2)
{
int a = 0;
while (s1[a] != '\0' && s2[a] != '\0')
{
if (s1[a] != s2[a])
{
return (s1[a] - s2[a]);
}
a++;
}
return (0);
}


/**
 * gone - removes \n from string
 * @s: input string
 * Return: void
 */
void gone(char *s)
{
size_t len = _strlen(s);
if (len > 0 && s[len - 1] == '\n')
{
s[len - 1] = '\0';
}
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str:input string
 *
 * Return: returns a pointer to the duplicated string.
 * It returns NULL if insufficient memory was available
 *
 */
char *_strdup(char *str)
{
int i, len = 0;
char *copied;
if (str == NULL)
{
return (NULL);
}
len = 0;
while (str[len] != '\0')
{
len++;
}
copied = (char *)malloc(len + 1);
if (copied == NULL)
{
return (NULL);
}
for (i = 0; i <= len; i++)
{
copied[i] = str[i];
}
return (copied);
}
