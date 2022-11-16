#include "shell.h"
/**
 * arr_size - finds size of array
 * @arr: array of pointers to strings
 * Return: size of the array
 */
int arr_size(char **arr)
{
	int i;

	if (arr == NULL || *arr == NULL)
		return (-1);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}
/**
 * array_to_list - builds a linked list of array of pointers
 * @array: array of pointers to strings
 * Return: pointer to head
 */
list_t *array_to_list(char **array)
{
	list_t *head;
	list_t *new;
	int i;

	head = NULL;
	for (i = 0; array[i] != NULL; i++)
	{
		new = add_node_end(&head, array[i]);
		if (new == NULL)
		{
			free_list(head);
			return (NULL);
		}
	}
	return (head);
}
/**
 * list_to_array - builds an array of pointers from linked list
 * @head: head pointer of the list
 * Return: pointer to array of pointers
 */
char **list_to_array(list_t **head)
{
	size_t len, i;
	list_t *tmp;
	char **array;

	len = list_len(*head);
	array = malloc(sizeof(char *) * (len + 1));
	if (array == NULL)
		return (NULL);
	tmp = *head;
	for (i = 0; i < len; i++)
	{
		array[i] = tmp->str;
		tmp = tmp->next;
	}
	array[i] = NULL;
	return (array);
}
/**
 * free_array - frees a 2D array
 * @array: array to free
 * Return: none
 */
void free_array(char **array)
{
	int i, size;

	size = arr_size(array);
	if (*array == NULL || array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] != NULL)
			free(array[i]);
	}
	free(array);
}
