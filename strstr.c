#include "shell.h"

/**
 * _strstr - function that return the number which joins two strings
 * @haystack: the character to print
 * @needle: another character to print
 *
 * Return: On success 1, or -1 ion error
 *
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0,  j, position;
	int count = 0, sizeofneedle = 0;

	while (*(needle + sizeofneedle))
	sizeofneedle++;
	if (sizeofneedle == 0)
	{
		return (&haystack[sizeofneedle]);
	}
	while (*(needle + i))
	{
		j = 0;
		while (*(haystack + j))
		{
			if (haystack[j] == needle[i])
			{
				count++;
				if (count == sizeofneedle)
			{
				position = j - count + 1;
			}
				break;
			}
			j++;
		}
		i++;
	}
	if (count == sizeofneedle)
	{
		return (&haystack[position]);
	}
	return (NULL);
}
