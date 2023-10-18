#include "sv_shell.h"

/**
 * main - entry point
 * @argv: array of arguments
 * @argc: length of the array
 *
 * Return: 0 success
 */

int main(int argc, char *argv[])
{
	(void)argc;
	handleUserInput(argv);
	return (0);
}
