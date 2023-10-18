#include "sv_shell.h"

/**
 * handleExitWithArgs - handles exit with args
 * @args: list of arguments
 *
 * Return: 0 on success
 */

int handleExitWithArgs(char **args)
{
	int exitStatus;
	char error[256] = "./hsh: 1: exit: Illegal number: ";

	if (args[1] != NULL)
	{
		exitStatus = atoi(args[1]);
		if (exitStatus > 0)
			exit(exitStatus);
		else if (exitStatus == 0 && _strcmp(args[1], "0") == 0)
			exit(0);
		else if (exitStatus < 0 || (exitStatus == 0 && _strcmp(args[1], "0") != 0))
		{
			_strcat(error, args[1]);
			_strcat(error, "\n");
			write(2, error, _strlen(error));
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
	if (_strcmp(args[0], "exit") == 0 && args[1] == NULL)
		exit(0);
	return (0);
}
