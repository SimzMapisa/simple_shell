#include "sv_shell.h"

/**
 * checkTabsOrNewline - checks for tabs and newline chars in user input
 * @str: string input
 * Return: 0
 */

int checkTabsOrNewline(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != '\t' && str[i] != '\n' && str[i] != ' ')
			return (0);
	}
	return (1);
}

/**
 * splitString - tokenises input
 * @buff: buffer
 * @delim: delimiter
 * Return: tokenised string
 */

char **splitString(char *buff, char *delim)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
	token = _strtok(buff, delim);

	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * printEnv - prints the environment
 * @env: environment path
 * Return: void
 */

void printEnv(char **env)
{
	int idx = 0;

	while (env[idx] != NULL)
	{
		printf("%s\n", env[idx]);
		idx++;
	}
}

/**
 * getCommand - gets user input commands
 * @command: user input
 * Return: 0
 */

char *getCommand(char *command)
{
	char *path = _getEnv("PATH");
	char *token;
	char *cmd_full;
	struct stat st;

	token = _strtok(path, ":");
	while (token)
	{
		cmd_full = malloc(strlen(token) + strlen(command) + 1);
		if (cmd_full == NULL)
			return (NULL);
		strcpy(cmd_full, token);
		strcat(cmd_full, "/");
		strcat(cmd_full, command);

		if (stat(cmd_full, &st) == 0)
			return (cmd_full);
		free(cmd_full);
		token = strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * _getEnv - searches for enviroment string pointed to by name
 * @env_var: input string
 * Return: value of the requested environment variable
 */

char *_getEnv(const char *env_var)
{
	int i = 0;
	char *key;

	while (environ[i])
	{
		key = _strtok(environ[i], "=");
		if (strcmp(env_var, key) == 0)
		{
			key = strtok(NULL, "\n");
			return (key);
		}
		i++;
	}
	return (NULL);
}
