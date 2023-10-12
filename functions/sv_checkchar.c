#include "sv_shell.h"

/**
 * checktabsornewline - checks for tabs and newline chars in user input
 * @str: string input
 * Return: 0
 */

int checktabsornewline(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != '\t' && str[i] != '\n' && str[i] != ' ')
			return (0);
	}
	return 1;
}
