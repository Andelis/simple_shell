#include "shell.h"

/**
 * _exec - execve implementation for simple shell
 * @command: command to execute
 * @cmd: command to execute
 * @env: command to execute
 *
 * Return: Always 0.
 *
 */
int _exec(char *command, char **cmd, char **env)
{
	if (execve(command, cmd, env) == -1)
	{
		perror("Error:");
	}

	return (0);
}
