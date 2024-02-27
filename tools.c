#include "main.h"

/**
 * _strlen - Get the length of a string without the NULL
 *
 * @s: the strings to be lengthed
 *
 * Return: the number of characters of the string
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _strcopy - Function that copies a string to an allocated memory
 *			for the new string
 *
 * @s: the string to be copied
 *
 * Return: the address of the new allocated string to be freed after use
 */
char *_strcopy(char *s)
{
	int len = _strlen(s);
	char *copy = NULL;

	copy = (char *)malloc((len + 1) * sizeof(char));
	if (copy == NULL)
	{
		perror("_strcopy malloc");
		exit(2);
	}
	_strcpy(copy, s);
	copy[len] = '\0';

	return (copy);
}
/**
 * _strcpy - Function to copy a string to another without allocating
 *
 * @dest: The destination string to copy in
 * @s: The source string to copy
 */
void _strcpy(char *dest, char *s)
{
	int i = -1;

	do {
		i++;
		dest[i] = s[i];
	} while (s[i] != '\0');
}
/**
 * _strcat - Function to concatenate 2 strings already allocated
 *
 * @dest: the destination string to concatenate into
 * @s: the source string to be concatenated
 */
void _strcat(char *dest, char *s)
{
	int x = 0, y = 0;

	while (dest[x])
		x++;

	for (y = 0; s[y]; y++)
		dest[x++] = s[y];

	dest[x] = '\0';
}
