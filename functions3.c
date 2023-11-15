#include "myshell.h"

/**
 * m_getenv - gets the environment variable
 * @name: name of environment
 * Return: the value of the environment variable
 */
char *m_getenv(const char *name)
{
size_t name_length = 0, j;
char **env_variable = NULL;
if (name == NULL || *name == '\0' || environ == NULL)
{
return (NULL);
}
while (name[name_length] != '\0' && name[name_length] != '=')
{
name_length++;
}
for (env_variable = environ; *env_variable != NULL; env_variable++)
{
for (j = 0; j < name_length && (*env_variable)[j] == name[j]; j++)
{
}
if (j == name_length && (*env_variable)[j] == '=')
{
return (*env_variable + j + 1);
}
}
return (NULL);
}

/**
 * my_puts - prints a string
 * @str: string to print
 */
void my_puts(const char *str)
{
while (*str)
{
_putchar(*str);
str++;
}
}

/**
 * my_putint - prints an integer
 * @num: integer to print
 */
void my_putint(int num)
{
char buffer[20];
int index = 0, a;

if (num < 0)
{
_putchar('-');
num = -num;
}
do {
buffer[index++] = num % 10 + '0';
num /= 10;
} while (num > 0);
for (a = index - 1; a >= 0; a--)
{
_putchar(buffer[a]);
}
}

/**
 * my_sprintf - prints a string
 * @buffer: buffer to print
 * @format: format to print
 * @...: extra arguments
 */
void my_sprintf(char __attribute__((unused)) *buffer, const char *format, ...)
{
va_list args;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'd':
my_putint(va_arg(args, int));
break;
case 's':
my_puts(va_arg(args, char *));
break;
default:
break;
}
}
else
{
_putchar(*format);
}
format++;
}
va_end(args);
}

/**
 * _fgetc - gets a character from a file
 * @stream: file to read
 * Return: character read
 */
int _fgetc(FILE *stream)
{
char i;
ssize_t readb = read(fileno(stream), &i, 1);

if (readb == 1)
{
return ((int)i);
}
else
{
return (EOF);
}
}
