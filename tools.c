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
	int len = 0;
	char *copy = NULL;

	if (s == NULL)
		return (NULL);

	len = _strlen(s);
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

/**
 * builtin - function that checks for the builtin commands and executes them
 *
 * @c_l: command line entered by the user
 * @pt: the arrays of strings of paths to be freed if exit
 * @c_c: the command lines entered by the user count
 * @e_c: the exit code
 * @av: the first argument of the main function
 * @ev: the environment variable
 *
 * Return: 0 if commands succeeded and 1 otherwise
 */
int builtin(char **c_l, char *pt[], int c_c, int *e_c, char *av, char *ev[])
{
	char *cpy_tok = NULL;
	char *cmd_copy = NULL;
	int hii;
	int i = 0;

	cmd_copy = _strcopy(*c_l);
	cpy_tok = _strcopy(strtok(cmd_copy, " "));
	free(cmd_copy);
	if (strncmp(cpy_tok, "exit", 4) == 0)
	{
		free(cpy_tok);
		hii = execExit(c_l, pt, c_c, e_c, av);
		if (hii == 0)
		{
			return (0);
		}
	}
	if (strncmp(cpy_tok, "cd", 2) == 0)
	{
		execCd(*c_l, ev);
		free(cpy_tok), free(*c_l);
		return (0);
	}
	if (strncmp(cpy_tok, "env", 3) == 0)
	{
		free(cpy_tok), free(*c_l);
		while (ev[i] != NULL)
		{
			printf("%s\n", ev[i]);
			i++;
		}
		return (0);
	}
	free(cpy_tok);
	return (1);
}
