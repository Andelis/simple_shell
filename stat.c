#include "shell.h"

/**
 * _stat - stat of a file
 * @myself: my own name as shell
 * @cmd: filename to be verified
 *
 * Return: 1 on success, 0 on failure
 *
 */
int _stat(char *myself, char *cmd)
{
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (1);
	error_handler(myself, 103);
	return (0);
}
