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
		_exit(0);
	}
	else if (pid == 0)
	{
		if (execve(command, argv, environ) == -1)
		{
			perror(command);
			_exit(0);
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
	char *token, *input = NULL;
	size_t len, size = 0;
	size_t len;
	const char delim[] = "\n";

	while (1)
	{
		if (isatty(STDIN_FILENO))
			displayPrompt();
		fflush(stdout);

		if (getline(&input, &size, stdin) == -1 || *input == EOF)
		{
			free(input);
			_exit(0);
		}
		len = _strlen(input);

		if (checktabsornewline(input) == 1)
		{
			return (0);
		}
		else
		{
			if (len > 0 && input[len - 1] == '\n')
				input[len - 1] = '\0';
			token = strtok(input, delim);

			if (len > 0)
			{
				if (_strcmp("/bin/ls", token) == 0)
				{
					executeCommand(token, argv);
					token = strtok(NULL, delim);
				}
				if (token && _strcmp("/bin/ls", input) != 0)
					write(2, "No such file or directory\n", 26);
			}
		}
	}
	free(input);
}
