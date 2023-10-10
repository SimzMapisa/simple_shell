#include "./functions/sv_shell.h"

/**
 * main - entry point
 * Return: 0 success
 */

int main(int argc, char *argv[])
{
	char input[1024];
	(void)argc;
	/*char *argv[] = {"/bin/ls", "-1", NULL};*/

	getUserInput(input, sizeof(input), argv);

	return (0);
}
