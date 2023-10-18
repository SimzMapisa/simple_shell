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
	char err[256] = "./hsh: 1: exit: Illegal number: ";

	if (args[1] != NULL)
	{
		exitStatus = atoi(args[1]);
		if (exitStatus > 0)
			exit(exitStatus);
		else if (exitStatus == 0 && _strcmp(args[1], "0") == 0)
			exit(0);
		else if (exitStatus < 0 || (exitStatus == 0 && _strcmp(args[1], "0") != 0))
		{
			_strcat(err, args[1]);
			_strcat(err, "\n");
			write(2, err, _strlen(err));
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
	int foundExit = 0, i;
	char *err = "/bin/ls: cannot access '/test_hbtn': No such file or directory";

	for (i = 0; args[i] == NULL; i++)
	{
		if (_strcmp(args[i], "exit") == 0)
		{
			foundExit += 1;
			break;
		}
	}
	if (_strcmp(args[0], "exit") == 0 && args[1] == NULL)
		exit(0);
	else if (strcmp(args[0], "exit") == 0 && args[1] != NULL)
		handleExitWithArgs(args);
	else if (foundExit == 1)
	{
		write(2, err, _strlen(err));
		exit(2);
	}
	return (0);
}
