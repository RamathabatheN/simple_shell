#include "myshell.h"

/**
 * main - Main entry point
 * for both the inactive and interactive shell
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
if (argc > 1 && strcmp(argv[1], "-i") == 0)
{
is_interactive_mode = 1;
interactive_shells();
}
else if (is_interactive_mode == 0)
{
shells();
}
return (EXIT_SUCCESS);
}
