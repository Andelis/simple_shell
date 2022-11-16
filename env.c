#include "shell.h"

/**
 * _getenv - gets an environment variable. (without using getenv)
 * @name: environment variable name
 * @env_head: pointer to environ list
 * Return: pointer to a string with that env variable or NULL if not found
 */
char *_getenv(char *name, list_t **env_head)
{
	list_t *tmp;
	int len, i;

	tmp = *env_head;
	len = list_len(tmp);
	if (!env_head || !tmp || !name)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (_strncmp(tmp->str, name, _strlen(name)) == 0)
			return (tmp->str);
		i++;
		tmp = tmp->next;
	}
	return (NULL);
}
/**
 * _setenv - changes or adds the variable to the environment with the value,
 *           if variable does not already exist. If it does exist in the
 *           environment, then its value is changed to value
 * @name: name of the variable
 * @value: value of the variable
 * @env_head: pointer to environ list
 * Return: pointer to head of the list or NULL if it failed
 */
int _setenv(char *name, char *value, list_t **env_head)
{
	char *ptr, *new_ptr;
	list_t *ret_ptr;

	new_ptr = var_str(name, value);
	if (new_ptr == NULL)
	{
		perror(ENOMEM);
		return (1);
	}
	/* use _getenv(name) to get a pointer to string of variable */
	ptr = _getenv(name, env_head);
	/* if variable not found add it */
	if (ptr == NULL)
	{
		ret_ptr = add_node_end(env_head, new_ptr);
		if (ret_ptr == NULL)
		{
			free(new_ptr);
			perror(ENOMEM);
			return (1);
		}
/* Error = ENOMEM if insufficient memory to add new var to the environment. */
		free(new_ptr);
		return (0);
	}
	/* replace it with new value */
	ret_ptr = get_node(env_head, ptr);
	free(ret_ptr->str);
	ret_ptr->str = new_ptr;
	return (0);
}
/**
 * _unsetenv - deletes the variable name from the environment. If name does
 *  not exist in the environment, then the function succeeds, and the
 *  environment is unchanged.
 * @name:name of the environment variable
 * @env_head: pointer to environ list
 * Return: Always 0 on success, or 1 on error
 */
int _unsetenv(char *name, list_t **env_head)
{
	char *equal;
	char *str_ptr;
	int deleted;
	list_t *tmp;

	tmp = *env_head;
	equal = _strchr(name, '=');
	if ((name == NULL) || ((name[0] == '\0') != 0) || (equal != NULL))
	{
		perror(EINVAL);
		return (1);
	}
	str_ptr = _getenv(name, &tmp);
	if (str_ptr == NULL)
	{
		perror("unsetenv: no such variable\n");
		return (1);
	}
	deleted = delete_node(&tmp, str_ptr);
	return (deleted);
}
/**
 * delete_node - deletes the node with string of a list_t
 * @head: pointer to head pointer
 * @string: pointer to the node that should be deleted
 * Return: 0 if it succeeded, 1 if it failed
 */
int delete_node(list_t **head, char *string)
{
	list_t *tmp;
	list_t *removeNode;

	tmp = *head;
	while (tmp && head)
	{
		if (_strcmp(tmp->str, string) == 0)
		{
			removeNode = *head;
			*head = removeNode->next;
			free(removeNode);
			return (0);
		}
		if (_strcmp((tmp->next)->str, string) == 0)
		{
			removeNode = tmp->next;
			tmp->next = removeNode->next;
			free(removeNode->str);
			free(removeNode);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
/**
 * var_str - creates new variable string
 * @name: name of the variable
 * @value: value of the variable
 * Return: pointer to new string or NULL if failed
 */
char *var_str(char *name, char *value)
{
	char *new_ptr;

/* Error = EINVAL if name is NULL, points to a string of length 0, */
	if (((name[0] == '\0') != 0) || (_strchr(name, '=') != NULL))
	{
		perror(EINVAL);
		return (NULL);
	}
/* or contains an '=' character or value is NULL */
	if ((name == NULL) || (value == NULL))
	{
		perror(ENOMEM);
		return (NULL);
	}
	/* create new string +2 for '=' and null terminator */
	new_ptr = malloc(_strlen(name) + _strlen(value) + 2);
/* Error = ENOMEM if insufficient memory to add new var to the environment. */
	if (new_ptr == NULL)
	{
		perror(ENOMEM);
		return (NULL);
	}
/*create a string with new variable name and a value */
	new_ptr = _strcpy(new_ptr, name);
	new_ptr = _strcat(new_ptr, "=");
	new_ptr = _strcat(new_ptr, value);
	return (new_ptr);
}
