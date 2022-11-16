#include "shell.h"
/**
 * built_ins - checks if command is a built-in
 * @input: tokenized line from the command line
 * @env_head: pointer to environ list
 * Return: 0 on success, 1 on error, -1 if not found
 */
int built_ins(char **input, list_t **env_head)
{
	builtin_t builtins[] = {
		{"exit", exit_bi},
		{"env", print_env},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{NULL, NULL}
	};
	int i, retval;
	list_t *tmp;

	tmp = *env_head;
	if (!input)
	{
		perror("built_ins");
		return (1);
	}
	i = 0;
	while ((builtins + i)->bi != NULL)
	{
		if (_strcmp(input[0], (builtins + i)->bi) == 0)
		{
			if (_strcmp(input[0], END) == 0)
			{
				retval = (builtins + i)->f(input);
				return (retval);
			}
			retval = (builtins + i)->f(input, &tmp);
			return (retval);
		}
		i++;
	}
	return (-1);
}
/**
 * exit_bi - exits shell with given status
 * @line: tokenized line from command line
 * Return: 0 on success, 1 on error
 */
int exit_bi(char **line)
{
	int size, status;

	size = arr_size(line);
	if (size > 2)
	{
		_strprint("Failed: Command syntax: exit status\n");
		return (1);
	}
	if (size == 1)
		return (0);
	if (size == 2)
	{
		status = _atoi(line[1]);
		return (status);
	}
	return (1);
}
/**
 * print_env - prints current environ
 * @line: tokenized line from command line
 * @env_head: pointer to environ list
 * Return: 0 on success, 1 on error
 */
int print_env(char **line, list_t **env_head)
{
	int size;
	list_t *tmp;

	tmp = *env_head;
	size = arr_size(line);
	if (size > 1)
	{
		_strprint("Failed: Command syntax: env\n");
		return (1);
	}
	print_list(tmp);
	return (0);
}
/**
 * set_env - initializes a new environment variable, or modify an existing one
 * @line: tokenized line from command line
 * @env_head: pointer to environ list
 * Return: 0 on success, 1 on error
 */
int set_env(char **line, list_t **env_head)
{
	int size;
	int retval;
	list_t *tmp;

	tmp = *env_head;
	size = arr_size(line);
	if (size != 3)
	{
		_strprint("Failed: Command syntax: setenv VARIABLE VALUE\n");
		return (1);
	}
	retval = _setenv(line[1], line[2], &tmp);
	return (retval);
}
/**
 * unset_env - removes environment variable
 * @line: tokenized line from command line
 * @env_head: pointer to environ list
 * Return: 0 on success, 1 on error
 */
int unset_env(char **line, list_t **env_head)
{
	int size, retval;
	list_t *tmp;

	tmp = *env_head;
	size = arr_size(line);
	if (size != 2)
	{
		_strprint("Failed: Command syntax: unsetenv VARIABLE\n");
		return (1);
	}
	retval = _unsetenv(line[1], &tmp);
	return (retval);
}
