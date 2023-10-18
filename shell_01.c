#include "sv_shell.h"

/**
 * main - entry point
 * @av: array of arguments
 * @ac: length of the array
 * @env: environmental variables
 *
 * Return: 0 success
 */

int main(int ac, char **av, char **env)
{
	char *input = NULL, *token, *input_cpy;
	int n_chars;
	size_t size = 0;
	char **args;
	(void)av;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "> ", 2);
		fflush(stdout);
		n_chars = getline(&input, &size, stdin);
		if (n_chars == -1)
		{
			free(input);
			exit(0);
		}
		if (checkTabsOrNewline(input) == 1)
			continue;
		if (n_chars > 0 && input[n_chars - 1] == '\n')
			input[n_chars - 1] = '\0';
		input_cpy = input;
		args = splitString(input, " \n");
		if (_strcmp(args[0], "env") == 0)
			printEnv(env);
		handleExit(args);
		handleExitWithArgs(args);
		token = strtok(input_cpy, " ");
		execCmd(token, args, env);
		free(args);
	}
	return (0);
}
