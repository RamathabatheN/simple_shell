#include "myshell.h"

/*int is_interactive_mode = 0;*/

/**
 * signal_handler - Handles signals
 * @signh: Signal number
 * Return: void
 */
void signal_handler(int signh)
{
int is_interactive_mode = 0;
ssize_t __attribute__((unused)) a;
if (signh == SIGINT)
{
if (is_interactive_mode)
{
a = write(STDOUT_FILENO, "\n$ ", 3);
fflush(stdout);
}
}
}
