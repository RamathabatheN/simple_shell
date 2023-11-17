#include "myshell.h"

/**
 * _allocate_line - Allocates memory for the line buffer
 * @line: pointer to the buffer to store the line
 * @n: size of the buffer
 * Return: 0 on success, -1 on failure
 */
int _allocate_line(char **line, size_t n)
{
*line = (char *)malloc(n);
return ((*line == NULL) ? -1 : 0);
}

/**
 * _getsline - Reads a line from the keyboard
 * @line: Pointer to the buffer to store the line
 * @n: Size of the buffer
 * @stream: Stream to read from
 * Return: The number of characters read
 */
ssize_t _getsline(char **line, size_t *n, FILE *stream)
{
int c;
size_t a = 0, new_sz;
char *new_ln;

if (line == NULL || n == NULL || stream == NULL)
return (EXIT_FAILURE);

if (*line == NULL && _allocate_line(line, 128) == -1)
return (EXIT_FAILURE);
while ((c = _fgetc(stream)) != EOF)
{
if (a >= *n - 1)
{
new_sz = *n * 2;
new_ln = (char *)my_realloc(*line, new_sz);
if (new_ln == NULL)
return (EXIT_FAILURE);
*line = new_ln;
*n = new_sz;
}
(*line)[a] = (char)c;
a++;
if (c == '\n')
break;
}
(*line)[a] = '\0';
if (a == 0)
return (EXIT_FAILURE);
return (a);
}
