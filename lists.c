#include "shell.h"
/**
 * list_len - returns the number of elements in a linked list_t list
 * @h: linked List
 * Return: number of elements
 */
size_t list_len(list_t *h)
{
	size_t len;

	len = 0;
	while (h != NULL)
	{
		len++;
		h = h->next;
	}
	return (len);
}
/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: first node in the list
 * @str: second node in the list
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, char *str)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = _strdup(str);
	if (new->str == NULL)
		return (NULL);
	new->len = _strlen(str);
	new->next = *head;
	*head = new;
	return (*head);
}
/**
 * add_node_end - check the code for Holberton School students.
 * @head: pointer to first node in linked list
 * @str: data to be copied to string field of the node
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, char *str)
{
	list_t *new;
	list_t *tail;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = _strdup(str);
	if (new->str == NULL)
		return (NULL);
	new->len = _strlen(str);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
		tail = *head;
		while (1)
		{
			if (tail->next == NULL)
			{
				tail->next = new;
				break;
			}
			tail = tail->next;
		}
	return (new);
}
/**
 * free_list - frees a list_t list
 * @head: linked list to free
 * Return: none
 */
void free_list(list_t *head)
{
	list_t *tmp;

	while (1)
	{
		if (head == NULL)
			break;
		tmp = head;
		head = tmp->next;
		free(tmp->str);
		free(tmp);
	}
}
/**
 * get_node - returns the node with string str
 * @head: pointer to first node
 * @str: string to search for
 * Return: n-th node, if the node does not exist, return NULL
 */
list_t *get_node(list_t **head, char *str)
{
	list_t *tmp;

	tmp = *head;
	while (head && tmp)
	{
		if (_strcmp(tmp->str, str) == 0 && tmp)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
