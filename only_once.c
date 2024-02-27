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
