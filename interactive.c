#include "myshell.h"

/**
 * interactive_shells - Entry point for interactive shell.
 * Return: Always 0
 */
int interactive_shells(void)
{
while (1)
{
char *input = NULL;
size_t len = 0;
ssize_t __attribute__((unused)) a;

a = write(STDOUT_FILENO, "$ ", 2);
if (_getsline(&input, &len, stdin) == -1)
{
perror("getline");
free(input);
exit(EXIT_FAILURE);
}
gone(input);
parse_execute(input, environ);
free(input);
}
return (EXIT_SUCCESS);
}

/**
 * child_execution - Executes the child process
 * @expanded_args: Expanded arguments
 * @envp: Environment
 * Return: void
 */
void child_execution(char **expanded_args, char **envp)
{
char *path, *token, path_buffer[256];
path = m_getenv("PATH");
token = _strtok(path, ":");

while (token != NULL)
{
if (expanded_args[0][0] == '/' || expanded_args[0][0] == '.')
{
_strcpy(path_buffer, expanded_args[0], sizeof(path_buffer));
}
else
{
_strcpy(path_buffer, "/bin/", sizeof(path_buffer));
_strcat(path_buffer, expanded_args[0], sizeof(path_buffer));
}
if (execve(path_buffer, expanded_args, envp) == -1)
{
token = _strtok(NULL, ":");
}
else
{
exit(EXIT_SUCCESS);
}
}
perror("execve");
_exit(EXIT_FAILURE);
}


/**
 * executing_command - Executes a command
 * @args: Arguments
 * @envp: Environment
 */
void executing_command(char **args, char **envp)
{
int status = 0, chilD_status, a;
char *expanded_args[100];
pid_t pid, __attribute__((unused)) wtpid;

for (a = 0; args[a] != NULL; a++)
{
expanded_args[a] = expand_env_vars(args[a], envp, status);
}
expanded_args[a] = NULL;
pid = fork();
if (pid == 0)
{
child_execution(expanded_args, envp);
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

/**
 * execute_command - Executes a single command
 * @command: Command string
 * @built_on: Array of built-in commands
 * @envp: Environment variables
 */
void execute_command(char *command, inside_s *built_on, char **envp)
{
char *args[100], *token, *inside;
int argc = 0, a;

token = _strtok(command, " \t\n");
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

char *commands[100], *token;
int command_counter = 0, i;

token = _strtok(input, ";");
while (token != NULL)
{
commands[command_counter++] = token;
token = _strtok(NULL, ";");
}
for (i = 0; i < command_counter; i++)
{
execute_command(commands[i], built_on, envp);
}
}
