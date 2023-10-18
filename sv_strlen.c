#include "sv_shell.h"

/**
 * _strlen - returns length of a string
 * @str:string input
 * Return: length
 */

int _strlen(const char *str)
{
	int i;
	int count = 0;

	for (i = 0; str[i] != '\0'; i++)
		count++;
	return (count);
}
