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
size_t a = 0, new_size;
char *new_line;
if (line == NULL || n == NULL || stream == NULL)
return (-1);
if (*line == NULL && _allocate_line(line, 128) == -1)
return (-1);
while ((c = _fgetc(stream)) != EOF)
{
if (a >= *n - 1)
{
new_size = *n * 2;
new_line = (char *)my_realloc(*line, new_size);
if (new_line == NULL)
return (-1);
*line = new_line;
*n = new_size;
}
(*line)[a] = (char)c;
a++;
if (c == '\n')
break;
}
(*line)[a] = '\0';
if (a == 0)
return (-1);
return (a);
}
