#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * struct error_msg - Structure for error messages
 * @ecode: error code
 * @msg: pointer to error message
 * @size: error message length
 *
 */
typedef struct error_msg
{
	int ecode;
	char *msg;
	int size;
} error_msg_t;

/**
 * struct built_s - Built-in commands
 * @command: command line
 * @f: function to call
 *
 * Description: Longer description
 */
typedef struct built_s
{
	char *command;
	void (*f)(char **);
} built_t;

/**
 * struct history - Structure for each command read
 * @id_h: error code
 * @comms: commands
 * @prev: previous element
 * @next: next element
 *
 */
typedef struct history
{
	unsigned int id_h;
	char *comms;
	struct history *prev;
	struct history *next;
} history_t;

/**
 * struct command_s - Structure for each command
 *
 * @command: command with argument(s)
 * @next: pointer to the next command
 */

typedef struct command_s
{
	char **command;
	struct command_s *next;
} command_t;

/* shell functions */
command_t **_prompt(char *, char *);
int _fork(char *, command_t *, char *, char **);
int _stat(char *, char *);
int _exec(char *, char **, char **);

/* vital utilities */
char *read_line(void);

size_t _strlen(char *str);
command_t *_parser_cmd(char *, char *);
size_t _parser_arg(char *, char **, size_t *);
void print_char_pointer_arr(char **, size_t);
int add_nodeint(history_t **head, char *str);
char *_strdup(char *str);
void free_listint(history_t *head);
char *find_path(char **);
char *_strstr(char *haystack, char *needle);
void print_env(char **);
char *_which(char *p_rec, char *first_arg);
char *string_nconcat(char *s1, char *s2, unsigned int n);
int _strcmp(char *s1, char *s2);
void _exit_func(char **);
int verif_built_comm(char *str, char **env);

/* error handlers */
void error_handler(char *, int);
void error_handler_set_default(int, char *);

/* command utilities */
command_t *new_cmd_node(char *);
void add_tok_to_cmd(char *, command_t *, size_t, char *);

#endif /* SHELL_H */
