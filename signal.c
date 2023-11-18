#include "myshell.h"

/*int is_interactive_mode = 0;*/

/**
 * signal_handler - Handles signals
 * @signh: Signal number
 * Return: void
 */
void signal_handler(int signh)
{
if (signh == SIGINT)
{
if ("EOF" == 0)
{
exit (0);
}
}
}
