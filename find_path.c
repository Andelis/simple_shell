#include "shell.h"

/**
 * *find_path - find the PATH
 * @environ: Environment vari\ble
 *
 * Return: string with path or NULL in failure
 *
 */
char *find_path(char **environ)
{
	char **env_ptr;
	char *aux;
	char *path;
	char *token;

	if (environ == NULL)
		return (NULL);

	for (env_ptr = environ; env_ptr != 0; env_ptr++)
	{
		aux = _strstr(*env_ptr, "PATH");
		if (aux != NULL)
		{
			path = _strdup(aux);
			token = strtok(path, "=");

			while (token != NULL)
			{
				token = strtok(NULL, "=");
				return (token);
			}
		}
	}
	return (NULL);
}

/**
 * print_env - print environment varibales
 *
 * @environ: environment variable
 *
 */
void print_env(char **environ)
{
	char **env_ptr;
	unsigned int size;

	env_ptr = environ;
	while (*env_ptr)
	{
		size = _strlen(*env_ptr);
		write(STDOUT_FILENO, *env_ptr, size);
		write(STDOUT_FILENO, "\n", 1);
		env_ptr++;
	}
}

/**
 * _which - find the directory of the command
 * @p_rec: path received
 * @first_arg: command
 *
 * Return: string with found path or NULL in failure.
 *
 */
char *_which(char *p_rec, char *first_arg)
{
	char *path, *arg, *path_tok, *command;
	unsigned int size;

	size = _strlen(first_arg);
	path = _strdup(p_rec);
	arg = strdup(string_nconcat("/", first_arg, size));
	size = _strlen(arg);
	path_tok = strtok(path, ":");

	while (path_tok != NULL)
	{
		command = string_nconcat(path_tok, arg, size);

		if (access(command, F_OK) == 0)
			return (command);
		path_tok = strtok(NULL, ":");
	}
	return (NULL);
}
