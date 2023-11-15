#include "myshell.h"

/**
 * parse_execute - Parses the command to be executed
 * @input: Input string
 * @envp: Environment variables
 */ 
void parse_execute(char *input, char **envp)
{
inside_s built_on[] = {
{"env", envr},
{"exit", exiting},
{"setenv", set_env},
{"unsetenv", unset_env},
{"cd", cD},
{NULL, NULL}
};

char *commands[100], *token, *args[100], *inside;
int command_counter = 0, __attribute__((unused)) status = 1, i, argc, a;

token = _strtok(input, ";");
while (token != NULL)
{
commands[command_counter++] = token;
token = _strtok(NULL, ";");
}
for (i = 0; i < command_counter; i++)
{
argc = 0;
token = _strtok(commands[i], " \t\n");
while (token != NULL)
{
if (token[0] == '#')
{
break;
}
args[argc++] = token;
token = _strtok(NULL, " \t\n");
}
args[argc] = NULL;
if (argc > 0)
{
inside = get_cmd(args);
if (inside != NULL)
{
for (a = 0; built_on[a].inside != NULL; a++)
{
if (_strcmp(built_on[a].inside, inside) == 0)
{
built_on[a].func(args);
continue;
}
}
}
else
{
executing_command(args, envp);
}
}
}
}

/**
 * executing_command - Executes a command
 * @args: Arguments
 * @envp: Environment
 */
void executing_command(char **args, char **envp)
{
int a, status = 0, chilD_status;
char *expanded_args[100], *path, *token, path_buffer[256];
pid_t pid, __attribute__((unused)) wtpid;

for (a = 0; args[a] != NULL; a++)
{
expanded_args[a] = expand_env_vars(args[a], envp, status);
}
expanded_args[a] = NULL;
pid = fork();
if (pid == 0)
{
path = m_getenv("PATH");
token = _strtok(path, ":");

while (token != NULL)
{
if (expanded_args[0][0] == '/' || expanded_args[0][0] == '.')
{
_strcpy(path_buffer, expanded_args[0]);
}
else
{
_strcpy(path_buffer, "/bin/");
_strcat(path_buffer, expanded_args[0]);
}
if (execve(path_buffer, expanded_args, envp) == -1)
{
token = _strtok(NULL, ":");
}
else
{
return;
}
}
perror("execve");
exit(1);
}
else if (pid < 0)
{
perror("fork");
}
else
{
do {
wtpid = waitpid(pid, &chilD_status, WUNTRACED);
} while (!WIFEXITED(chilD_status) && !WIFSIGNALED(chilD_status));
status = WEXITSTATUS(chilD_status);
}
}
