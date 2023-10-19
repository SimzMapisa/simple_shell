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
	char e[256] = ": cannot access '/test_hbtn': No such file or directory";

	if (args[1] != NULL)
	{
		exitStatus = atoi(args[1]);
		if (exitStatus > 0)
			exit(exitStatus);
		if (exitStatus == 0 && _strcmp(args[1], "0") == 0)
			exit(0);
		if (exitStatus == 0 && strcmp(args[1], "0") != 0)
		{
			strcat(e, args[1]);
			strcat(e, "\n");
			write(2, e, _strlen(e));
			exit(2);
		}
		else
		{
			exit(exitStatus);
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
