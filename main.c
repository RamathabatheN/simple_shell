#include "myshell.h"

/**
 * main - Main entry point
 * for both the inactive and interactive shell
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: Always 0
 */
int main(int argc, char *argv[], char **envp)
{
if (argc > 1)
{
if (strcmp(argv[1], "./hsh") == 0)
{
envr(envp);
return (EXIT_SUCCESS);
}
else
{
my_sprintf("Usage: %s \n", argv[0]);
return (-1);
}
}
signal(SIGINT, signal_handler);

interactive_shells();

/*fflush(stdin);
fflush(stdout);*/

return (EXIT_SUCCESS);
}
