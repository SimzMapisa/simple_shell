#include "sv_shell.h"

/**
 * handleExitWithArgs - handles exit with args
 * @args: list of arguments
 *
 * Return: 0 on success
 */

int handleExitWithArgs(char **toks)
{
	int exit_Status;
	char err[300] = "./hsh: 1: exit: Illegal number: ";

	if (toks[1] != NULL)
	{
		exit_status = atoi(toks[1]);
		if (exit_status > 0)
			exit(exit_status);
		else if (exit_status == 0 && strcmp(toks[1], "0") == 0)
			exit(0);
		else if (exit_status < 0 || (exit_status == 0 && strcmp(toks[1], "0") != 0))
		{
			strcat(err, toks[1]);
			strcat(err, "\n");
			write(2, err, strlen(err));
			exit(2);
		}
	}
	return (0);
}

/**
 * handleExit - handles exit of a program
 * @args: lists of commanline args
 *
 * Return: int
 */

int handleExit(char **args)
{
	if (args == NULL)
	{
		return (127);
	}
	if (_strcmp(args[0], "exit") == 0 && args[1] == NULL)
		exit(0);
	return (0);
}
