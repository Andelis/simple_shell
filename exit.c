#include "shell.h"

/**
 * _exit_func - function to exit successfully
 *
 * @environ: Environment variables
 *
 */
void _exit_func(char **environ)
{
	(void)environ;
	exit(98);
}
