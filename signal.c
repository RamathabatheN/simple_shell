#include "myshell.h"

/**
 * signal_handler - Handles signals
 * @signh: Signal number
 * Return: void
 */
void signal_handler(int signh)
{
ssize_t a;
if (signh == SIGINT)
{
if (is_interactive_mode)
{
a = write(STDOUT_FILENO, "\n$ ", 3);
fflush(stdout);
}
}
