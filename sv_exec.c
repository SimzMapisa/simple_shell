#include "sv_shell.h"

/**
 * execCmd - executes the program
 * @token: tokenised user input
 * @args: array of argumt strings
 * @env: environment variables
 *
 * Return: void
 */

void execCmd(char *token, char **args, char **env)
{
	pid_t pid;
	int status;
	char *cmd;

	pid = fork();
	if (pid == 0)
	{
		if ((strcmp(token, "/bin/ls") == 0) || (strcmp(token, "/bin/echo") == 0))
		{
			execve(token, args, env);
			token = _strtok(NULL, " ");
		}
		cmd = getCommand(args[0]);
		if (cmd)
			execve(cmd, args, env);
		else
		{
			perror(cmd);
			exit(status);
		}
	}
	else
		wait(&status);
}
