#include "shell.h"
/**
 * _strlen - returns the lenght of a string
 * @s: pointer to s
 * Return: 0 on success
 */
int _strlen(char *s)
{
	int count = 0;

	if (s != 0)
	{
		while (*(s + count) != 0)
			count++;
	}
	return (count);
}
/**
 * _strncmp - compares two strings for n amount of chars
 * @s1: pointer to string s1
 * @s2: pointer to string s2
 * @n: number of chars to compare
 * Return: 0 if identical
 *
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i, dif;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return (-1);
		if (s1[i] != s2[i])
		{
			dif = s1[i] - s2[i];
			return (dif);
		}
		i++;
	}
	return (0);
}
/**
 * _strcpy - copies the string with \0 to the buffer
 * @dest: pointer to dest
 * @src: pointer to string
 *
 * Return: the pointer to dest
 *
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
/**
 * _strcat - appends the src string to the dest string
 * @dest: pointer to dest string
 * @src: pointer to src string
 *
 * Return: pointer to resulting string dest
 *
 */
char *_strcat(char *dest, char *src)
{
	int i, length;

	length = _strlen(dest);

	for (i = 0 ; src[i] != '\0' ; i++)
		dest[length + i] = src[i];
	dest[length + i] = '\0';

	return (dest);
}
/**
 * _strdup - returns a pointer to a newly allocated space in memory, which
*           contains a copy of the string given as a parameter
* @str: string to copy
* Return: pointer to new string or NULL if str = NULL
*/
char *_strdup(char *str)
{
	int i, len;
	char *new_str;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		new_str[i] = str[i];
	new_str[len] = '\0';
	return (new_str);
}
