#include "sv_shell.h"
#include <stddef.h>

/**
 * _strcmp - compares two strings
 * @str1: first input
 * @str2: second input
 * Return: void
 */

int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	if (str1 == NULL || str2 == NULL)
		return (1);
	if (_strlen(str1) < _strlen(str2) || _strlen(str1) > _strlen(str2))
		return (1);

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (1);
	}
	return (0);
}
