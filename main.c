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
shells();
}
else
{
interactive_shells();
}
return (EXIT_SUCCESS);
}
