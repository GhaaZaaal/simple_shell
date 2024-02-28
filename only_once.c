#include "main.h"

/**
 * toknizing_envp_path - Function that takes the environment from the main
 *			and search for the paths and creates an array of strings containg
 *			the paths one by one
 * @envp: the environment from the main
 *
 * Return: the array of strings containg the paths
 */
char **toknizing_envp_path(char *envp[])
{
	int i = 0;
	char *path_string = NULL;
	int counter = 1;
	char *paths_counter = NULL;
	char **path_toknized = NULL;
	char *tmp_to_add_to_path_array = NULL;

	while (envp[i] != NULL)
	{
		if (strncmp(envp[i], "PATH", 4) == 0)
		{
			path_string = _strcopy(envp[i] + 5); /*  malloced for path string */
			break;								 /*  + 5 execluded the "PATH=" */
		}
		i++;
	}

	paths_counter = _strcopy(path_string); /* malloced for path copy to count */
	strtok(paths_counter, ":");
	while (strtok(NULL, ":") != NULL)
	{
		counter++;
	}
	free(paths_counter); /* freed path copy */

	path_toknized = (char **)malloc((counter + 1) * sizeof(char *));
	/* malloced for array of strings */

	tmp_to_add_to_path_array = strtok(path_string, ":");
	i = 0;
	while (tmp_to_add_to_path_array != NULL)
	{
		path_toknized[i] = _strcopy(tmp_to_add_to_path_array);
		tmp_to_add_to_path_array = strtok(NULL, ":");
		i++;
	}
	path_toknized[i] = NULL;
	free(path_string); /* freed path string */

	return (path_toknized); /*  need to be freed after */
}
/**
 * free_array - Function to free an array of strings
 *
 * @array: the array to be freed
 */
void free_array(char *array[])
{
	int count = 0;

	while (array[count] != NULL)
	{
		free(array[count]);
		count++;
	}
	free(array);
}

/**
 * execExit - function to exit our program
 *
 * @cmd_line: the command line entered by the user
 * @counter: the count of tokens in the command line
 */
void execExit(char **cmd_line, int counter)
{
	int exit_code = 0;

	if (counter > 1)
	{
		exit_code = atoi(*cmd_line + 5);
		free(*cmd_line);
		exit(exit_code);
	}
	free(*cmd_line);
	exit(exit_code);
}

/**
 * check_if_spaces - function to check if a string is only spaces
 *
 * @cmd_line: the command line entered by the user
 *
 * Return: if the string is only spaces -1, otherwise 0
 */
int check_if_spaces(char *cmd_line)
{
	int i = 0;
	int x = 0;

	x = _strlen(cmd_line);
	while (*cmd_line != '\0')
	{
		if (strncmp(cmd_line++, " ", 1) == 0)
		{
			i++;
		}
	}
	if (i == x)
	{
		return (-1);
	}
	else
		return (0);
}

/**
 * execCd - function to execute cd command
 *
 * @cmd: the command line to execute the args
 * @envp: the environment variable to look for the old path
 */
void execCd(char *cmd, char *envp[])
{
	int i = 0;
	char *home_path = NULL;
	char *cmd_tokp = NULL;
	char *tokstr = NULL;

	while (envp[i] != NULL)
	{
		if (strncmp(envp[i], "HOME", 4) == 0)
		{
			home_path = envp[i] + 5;
			break;
		}
		i++;
	}
	tokstr = strtok(cmd, " ");
	if (tokstr != NULL)
	{
		tokstr = strtok(NULL, " ");
		cmd_tokp = tokstr;
	}
	else
		cmd_tokp = NULL;

	if (cmd_tokp == NULL)
		chdir(home_path);
	else if (chdir(cmd_tokp) != 0)
		perror("cd");
}
