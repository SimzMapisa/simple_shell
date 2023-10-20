#include "sv_shell.h"

/**
 * _strtok - tokenizes input
 * @str: input string
 * @delim: delimeter
 *
 * Return: an array of strings
 */

 char *_strtok(char *str, const char *delim)
{
	return (strtok(str, delim));
}
