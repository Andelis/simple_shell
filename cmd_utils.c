#include "shell.h"

/**
 * new_cmd_node - creates a new node for command struct
 * @myself: my own name as shell
 *
 * Return: On success, 1 or -1 when unsuccessful.
 */

command_t *new_cmd_node(char *myself)
{
	command_t *cmd_node = NULL;

	cmd_node = malloc(sizeof(command_t));
	if (!cmd_node)
		error_handler(myself, 105);

	cmd_node->command = malloc(sizeof(char *));
	if (!cmd_node->command)
		error_handler(myself, 105);
	return (cmd_node);
}

/**
 * add_tok_to_cmd - Add token from the command line to command mode
 * @sh: my own name as shell.
 * @cmd_node: Command node to be updated.
 * @index: position to add token.
 * @token: to be added.
 *
 * Return: 1 on success, -1 on error
 */

void add_tok_to_cmd(char *sh, command_t *cmd_node, size_t index, char *token)
{
	cmd_node->command[index] = strdup(token);
	if (!cmd_node->command[index])
		error_handler(sh, 105);
}
