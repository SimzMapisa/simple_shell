#include "sv_shell.h"

/**
 * executeCommand - executes the command if found
 * @command: pointer to the command to be executed
 * @argv: an array of args
 *
 * Return: Nothing
 */

void executeCommand(char *command, char *argv[])
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("Fork Error");
		_exit(1);
	}
	else if (pid == 0)
	{
		if (execve(command, argv, environ) == -1)
		{
			perror(command);
			_exit(1);
		}
	}
	else
		wait(&status);
}

/**
 * handleUserInput - handle the input from the user
 * @argv: a list of arguments from user
 *
 * Return: Nothing
 */

void handleUserInput(char *argv[])
{
	char *input = NULL;
	size_t size = 0;
	size_t len;

	while (1)
	{
		displayPrompt();
		fflush(stdout);

		if (getline(&input, &size, stdin) == -1 || *input == EOF)
		{
			free(input);
			_exit(1);
		}
		len = _strlen(input);
		if (len > 0 && input[len - 1] == '\n')
			input[len - 1] = '\0';
		if (_strcmp("/bin/ls", input) == 0)
			executeCommand("/bin/ls", argv);
		if (_strcmp(input, "") != 0 && _strcmp("/bin/ls", input) != 0)
			write(2, "No such file or directory\n", 26);
		else
			continue;
	}
	free(input);
}
