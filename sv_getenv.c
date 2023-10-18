#include "sv_shell.h"

#define PATHSIZE 1024

/**
 * _getenv - searches for the enviroment string pointed to by name
 * @name: string containing the name of the requested variable
 * Return: value of the requested environ variable
 */

char *_getenv( const char *name)
{
	char *temp, myPath[PATHSIZE] = "";

	temp = _getenv(name);

	if (temp == NULL)
	{
		printf("no PATH variable set.\n");
	}
	return (temp);
}
