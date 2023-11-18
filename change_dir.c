#include "myshell.h"

/**
 * cD - changes the directory
 * @command: input string
 * Return: Always 0
 */
int cD(char **command)
{
int i;
ssize_t q;
char *old_dir = NULL, *new_dir = NULL, *prev_dir = NULL;

if (command[1] == NULL)
{
old_dir = getcwd(NULL, 0);
i = chdir(m_getenv("HOME"));
new_dir = m_getenv("HOME");
}
else if (_strcmp(command[1], "-") == 0)
{
old_dir = getcwd(NULL, 0);
prev_dir = m_getenv("OLDPWD");
if (prev_dir != NULL)
{
i = chdir(prev_dir);
new_dir = prev_dir;
}
else
{
q = write(STDERR_FILENO, "cd: OLDPWD not set\n", 19);
i = -1;
}
}
else
{
old_dir = getcwd(NULL, 0);
if (chdir(command[1]) != 0)
{
perror("chdir");
return (-1);
}
new_dir = getcwd(NULL, 0);
}
if (new_dir != NULL)
{
setenv("PWD", new_dir, 1);
}
if (old_dir != NULL)
{
setenv("OLDPWD", old_dir, 1);
}
free(old_dir);
free(new_dir);
return (EXIT_SUCCESS);
}
