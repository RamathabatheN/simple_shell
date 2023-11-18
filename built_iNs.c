#include "myshell.h"

/**
 * exiting - exits the shell
 * @command: input string
 * Return: Always 0
 */
int exiting(char **command)
{
int status;
if (_strcmp(command[0], "exit") == 0)
{
if (command[1] != NULL)
{
status = atoi(command[1]);
exit(status);
}
else
{
exit(EXIT_SUCCESS);
}
}
return (EXIT_SUCCESS);
}

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

int a = 0;
for (a = 0; built_on[a].inside; a++)
{
if (_strcmp(command[0], built_on[a].inside) == 0)
{
return (built_on[a].inside);
}
}
return (NULL);
}
