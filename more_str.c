#include "shell.h"
/**
 * _strcmp - compares two strings
 * @s1: pointer to string s1
 * @s2: pointer to string s2
 * Return: difference in value of first char that's different
 */
int _strcmp(char *s1, char *s2)
{
	int i, dif;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			dif = s1[i] - s2[i];
			return (dif);
		}
		i++;
	}
	if (s1[i] == s2[i] && s1[i] == '\0')
		dif = 0;
	return (dif);
}
/**
 * _strchr - locates character in string
 * @str: pointer to a string
 * @c: char to find
 * Return: pointer to the matched character or NULL
 */
char *_strchr(char *str, char c)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
			return ((char *)(str + i));
	}
	return (NULL);
}
/**
 * len_to_char - finds string length to passed char
 * @str: pointer to a string
 * @c: char to find
 * Return: length of string before char or 0 if not found
 */
int len_to_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (0);
	return (i);
}
/**
 * _atoi - converts string to integer
 * @s: pointer to string to print
 * Return: number or -1 on error
 */
int _atoi(char *s)
{
	int size, number, exponent, i;

	size = _strlen(s);
	exponent = 1;
	for (i = 1; i < size; i++)
		exponent *= 10;
	number = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			number += (s[i] - '0') * exponent;
		else
		{
			perror("wrong input for exit status\n");
			return (-1);
		}
		exponent /= 10;
	}
	return (number);
}
