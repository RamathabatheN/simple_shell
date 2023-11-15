#ifndef MYSHELL_H
#define MYSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>


typedef struct inside
{
char *inside;
int (*func)(char **command);
} inside_s;

extern char **environ;
int shells(void);
void executing_command(char **args, char **envp);
void parse_execute(char *input, char **envp);
char *get_cmd(char **command);
int envr(char **command);
int exiting(char **command);
int cD(char **command);
int set_env(char **command);
int unset_env(char **command);
int a_alias(char **command);
int shell_s(void);
ssize_t _getsline(char **line, size_t *n, FILE *stream);
void gone(char *s);
char *_strtok(char* str, const char* delim);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(const char *s, char c);
size_t _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _putchar(char c);
void my_puts(const char *str);
void my_putint(int num);
void my_sprintf(char *buffer, const char *format, ...);
char *m_getenv(const char *name);
char *expand_env_vars(char *input, char **envp, int status);
int _fgetc(FILE *stream);

#endif