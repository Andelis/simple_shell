
#include "shell.h"

/**
 * _getline - prints "$ ", wait for the user to enter a command, prints it on
 *  the next line
 * @input: pointer to buffer to store input
 * @size: size of a buffer
 * Return: chars read or -1 if _realloc failed
 */
int _getline(char *input, int size)
{
	int i;
	int readval;
	struct stat sb;

	if (fstat(STDIN_FILENO, &sb) == -1)
	{
		perror("fstat");
		exit(-1);
	}
	if ((sb.st_mode & S_IFMT) != S_IFIFO)
		_strprint(PROMPT);
	for (i = 0; i < size - 1; i++)
	{
		readval = read(STDIN_FILENO, (input + i), 1);
		if (readval == 0)
			return (-1); /* EOF  */
		if (input[i] == '\n')
			break;
	}
	input[i] = '\0';
	return (i);
}
/**
 * exit_shell - if user types 'exit' exit shell
 * @line_tok: pointer to a tokenized input line
 * Return: 1 if want to exit, 0 otherwise
 */
int exit_shell(char **line_tok)
{
	int cmp, lend, lline, size;

	size = arr_size(line_tok) < 3;
	cmp = _strncmp(line_tok[0], END, _strlen(END));
	lend = _strlen(END);
	lline = _strlen(line_tok[0]);
	if (cmp == 0 && lend == lline && size)
		return (1);
	return (0);
}
/**
 * clear_buffer - sets all the chars in buffer to 0
 * @buffer: buffer to reset
 * Return: nothing
 */
void clear_buffer(char *buffer)
{
	int i;

	for (i = 0; i < BUFF_SIZE; i++)
		buffer[i] = 0;
}
/**
 * mem_cpy - copies memory area
 * @dest: memory area to copy to
 * @src: memory area copying from
 * @n: how many bytes to copy
 * Return: Pointer to dest
 */
char *mem_cpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n - 1; i++)
	{
		*(dest + i) = *(src + i);
	}
	*(dest + i) = '\0';
	return (dest);
}
/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes of the new memory block
 *
 * Return: returns pointer to new memory location
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *array, *helper;
	unsigned int i;

	if (old_size == new_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		array = malloc(new_size);
		if (array == NULL)
			return (NULL);
		return (array);
	}
	array = malloc(sizeof(char) * new_size);
	if (array == NULL)
		return (NULL);
	if (new_size > old_size && old_size != 0)
	{
		helper = ptr;
		for (i = 0; i < old_size; i++)
			array[i] = helper[i];
		free(ptr);
	}
	if (new_size < old_size)
	{
		helper = ptr;
		for (i = 0; i < new_size; i++)
			array[i] = helper[i];
		free(ptr);
	}
	return (array);
}
