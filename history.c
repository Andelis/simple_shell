#include "shell.h"

/**
 * *add_nodeint - add node at the beginning
 * @head: the pointer of the history list
 * @str: the string received
 *
 * Return: On success 1
 *
 */
int add_nodeint(history_t **head, char *str)
{
	history_t *new = malloc(sizeof(head));
	history_t *copy = *head;

	if (!new)
	{
		free_listint(*head);
		return (-1);
	}

	new->comms = _strdup(str);

	if (new->comms == NULL)
	{
		free_listint(*head);
		return (-1);
	}

	new->prev = NULL;
	new->next = NULL;

	if (!*head)
	{
		*head = new;
	}
	else
	{
		new->next = copy;
		*head = new;
	}
	return (1);
}

/**
 * free_listint - print the list of a single list
 * @head: the pointer of the list
 *
 * Return: The number of elements in the list.
 *
 */
void free_listint(history_t *head)
{
	history_t *delete;

	if (!head)
		return;

	while (head)
	{
		delete = head->next;
		free(head->comms);
		free(head->prev);
		free(head);
		head = delete;
	}
	free(delete);
}

/**
 * print_listint - print trhe list of a single list
 * @h: the pointer of the list.
 *
 * Return: the number of elements in the list.
 *
 */
void print_listint(const history_t *h)
{
	while (h)
	{
		printf(":DEBUG history :%s\n", h->comms);
		h = h->next;
	}
}
