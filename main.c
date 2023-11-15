#include "myshell.h"

/**
 * main - Main entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
if (argc > 1 && strcmp(argv[1], "-i") == 0)
{
interactive_shells();
}
else
{
shells();
}
interactive_shells();
return (0);
}
