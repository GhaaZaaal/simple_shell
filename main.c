#include "main.h"

/**
 * main - the main function of our easy simple shell
 *
 * @argc: number of arguments
 * @argv: arguments array
 * @envp: array of environment
 *
 * Return: always 0
 */
int main(int argc, char *argv[], char *envp[])
{
	char *cmd_line = NULL;
	size_t cmd_len = 512;
	int counter = 1;
	char **path_array = toknizing_envp_path(envp);

	(void)argc;
	(void)argv;
	while (1)
	{
		if (isatty(fileno(stdin)))
		{
			display_prompt();
		}
		user_input(&cmd_line, cmd_len, path_array, counter++);
		/* counter++; */
	}
	free_array(path_array);
	return (0);
}
