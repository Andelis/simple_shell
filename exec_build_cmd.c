#include "shell.h"

/**
 * verif_built_comm - Execute teh built-in commands.
 * @str: first argument
 * @env: environment variable
 *
 * Return: 0 when successful or -1 when unsuccessful
 *
 */
int verif_built_comm(char *str, char **env)
{
	int iterator, result;
	built_t built_func[] = {
		{"env", print_env},
		{"exit", _exit_func},
		{NULL, NULL}
	};

	for (iterator = 0; built_func[iterator].command != NULL; iterator++)
	{
		result = _strcmp(str, built_func[iterator].command);
		if (result == 0)
		{
			built_func[iterator].f(env);
			return (1);
		}
	}

	return (0);
}
