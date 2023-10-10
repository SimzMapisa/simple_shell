#include "./functions/sv_shell.h"

/**
 * main - entry point
 * Return: 0 success
 */

int main(int argc, char *argv[])
{
	char input[1024];

	(void)argc;
	getUserInput(argv[0], sizeof(input));
	return (0);
}
