#include "shell.h"
/**
 * path_dirs_array - makes array of pointers for all dirs in the PATH
 * @env_head: pointer to environ list
 * Return: Array of pointers
 */
char **path_dirs_array(list_t **env_head)
{
	char *ptr;
	char *name = "PATH";
	char *path_str;
	char delim = ':';
	char **dirs;
	list_t *tmp;

	tmp = *env_head;
	/* get string PATH=... from environment */
	ptr = _getenv(name, &tmp);
	/* duplicate string starting at char after = */
	path_str = _strdup(ptr + 5);
	/* tokenize into separate string dirs */
	dirs = strtow(path_str, delim);
	if (dirs == NULL)
	{
		free(path_str);
		return (NULL);
	}
	free(path_str);
	return (dirs);
}
/**
 * cmd_in_path - finds command in the PATH
 * @str: pointer to first string in input line (command)
 * @env_head: pointer to environ list
 * Description: steps
 * tokenize path directories
 * check if str in path and then concat command to PATH directories
 * use access sys_call to see if it's binary executable
 * realloc memory for cmd +2 = +1 for '/' +1 for '\0'
 * Return: pointer to absolute path of command or NULL if not found
 */
char *cmd_in_path(char *str, list_t **env_head)
{
	char **path_dirs, *cmd;
	int i, j, cmdl, strl;
	list_t *tmp;

	for (j = 0; str[j] != '\0'; j++)
	{
		if (str[j] == '/' && str[j + 1] != '\0' && str[j + 1] != '/' &&
		    access(str, F_OK | X_OK) == 0)
			return (str);
	}
	if ((str[0] == '/' || str[0] == '.') && str[j] == '\0')
	{
		_strprint(str);
		_strprint(": not found\n");
		return (NULL);
	}
	tmp = *env_head;
	path_dirs = path_dirs_array(&tmp);
	if (path_dirs == NULL)
	{
		perror(ENOMEM);
		return (NULL);
	}
	for (i = 0; path_dirs[i] != NULL; i++)
	{
		cmd = _strdup(path_dirs[i]);
		cmdl = _strlen(cmd);
		strl = _strlen(str);
		cmd = _realloc(cmd, cmdl, cmdl + strl + 2);
		cmd = _strcpy(cmd, path_dirs[i]);
		cmd = _strcat(cmd, "/");
		cmd = _strcat(cmd, str);
		if (access(cmd, F_OK) == 0)
		{
			free_array(path_dirs);
			return (cmd);
		}
	}
	free_array(path_dirs);
	return (str);
}
/**
 * run_command - runs the command typed into shell prompt
 * @line_tok: tokenized input line
 * @env_head: pointer to environ list
 * Return: Always 0 on success, 1 on error
 */
int run_command(char **line_tok, list_t **env_head)
{
	pid_t child_pid;
	int status;
	char **env_array;
	char *command;
	list_t *tmp;

	tmp = *env_head;
	env_array = list_to_array(&tmp);
	if (env_array == NULL)
	{
		perror(ENOMEM);
		return (1);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("run_command: child pid is -1");
		free(env_array);
		return (1);
	}
	if (child_pid == 0)
	{
		/* find command (first token) in the PATH */
		command = cmd_in_path(line_tok[0], &tmp);
		if (command == NULL)
			exit(1);
		/* run execve (abs path, rest of the tokens, env) */
		if (execve(command, line_tok, env_array) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
	free(env_array);
	return (0);
}
