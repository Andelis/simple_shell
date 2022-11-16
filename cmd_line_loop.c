#include "shell.h"
/**
 * cmd_line_loop - calls getline until user enters exit or EOF(ctrl^D)
 * @buffer: pointer to buffer to store input
 * @line: pointer to a string of line input
 * @env_head: pointer to head of environ list
 * Return: 0 on success or 1 if _realloc failed
 */
int cmd_line_loop(char *buffer, char *line, list_t **env_head)
{
	int chars_read, old_len, retval = 0;
	char **line_tok;
	list_t *tmp;

	tmp = *env_head;
	while (1)
	{
		clear_buffer(buffer);
		chars_read = _getline(buffer, BUFF_SIZE);
		if (chars_read == -1)  /* EOF  */
			break;
		if (line == NULL)
			old_len = 0;
		else
			old_len = _strlen(line);
		line = _realloc(line, old_len, ++chars_read); /* ++ for \0  */
		if (line == NULL)
		{
			perror("ENOMEM");
			retval = 1;
			break;
		}
		line = mem_cpy(line, buffer, chars_read);
		if (line[0] != '\0')
		{
			line_tok = strtow(line, ' '); /* tokenize input line */
			retval = built_ins(line_tok, &tmp); /* if built-in */
			if (exit_shell(line_tok) && retval != -1) /* if exit */
			{
				free_array(line_tok);
				break;
			}
			if (retval == -1) /*not builtin,check if binary exe*/
				retval = run_command(line_tok, &tmp);
			free_array(line_tok);
		}
	}
	free(line);
	return (retval);
}
