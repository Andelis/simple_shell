#include "shell.h"

/**
 * _parser_cmd - parses a simple command from the prompt.
 *
 * @cmd_line: command line to be parsed from prompt
 * @myself: my own name as shell.
 *
 * Return: NULL or pointer to command node
 *
 */
command_t *_parser_cmd(char *myself, char *cmd_line)
{
	size_t i = 0;
	char *cmd_str = NULL;
	const char *arg_sep = " \n";
	command_t *cmd_node = NULL;

	cmd_str = strtok(cmd_line, arg_sep);
	if (cmd_str)
	{
		cmd_node = new_cmd_node(myself);
		add_tok_to_cmd(myself, cmd_node, i, cmd_str);

		while (cmd_str != NULL)
		{
			cmd_str == NULL ? i : i++;
			cmd_str = strtok(NULL, arg_sep);
			if (cmd_str)
				add_tok_to_cmd(myself, cmd_node, i, cmd_str);
		}
	}

	return (cmd_node);
}
