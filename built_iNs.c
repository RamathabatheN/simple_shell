#include "myshell.h"

/**
 * get_cmd - used for execution
 * @command: input string
 * Return: executed command
 */
char *get_cmd(char **command)
{
inside_s built_on[] = {
{"env", envr},
{"exit", exiting},
{"setenv", set_env},
{"unsetenv", unset_env},
{"cd", cD},
{NULL, NULL}
};

int a = 0, __attribute__((unused)) on = -1;
static char __attribute__((unused)) **argv;
for (a = 0; built_on[a].inside; a++)
{
if (_strcmp(command[0], built_on[a].inside) == 0)
{
return (built_on[a].inside);
}
}
return (NULL);
}

/**
 * exiting - exits the shell
 * @command: input string
 * Return: Always 0
 */
int exiting(char **command)
{
if (_strcmp(command[0], "exit") == 0)
{
_exit(2);
}
return (EXIT_SUCCESS);
}

/**
 * cD - changes the directory
 * @command: input string
 * Return: Always 0
 */
int cD(char **command)
{
int __attribute__((unused)) i;
ssize_t __attribute__((unused)) q;
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
q = write(STDERR_FILENO, "cd: OLDPWD not set\n", 20);
i = -1;
}
}
else
{
old_dir = getcwd(NULL, 0);
if (chdir(command[1]) != 0)
{
perror("chdir");
return (EXIT_FAILURE);
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
return (EXIT_SUCCESS);
}
