#include "sv_shell.h"

/**
 * _status - records exit code status
 * @cmd: input command
 * Return: exit status
 */

int _status(char *cmd)
{
	if (cmd == NULL)
		return (127);

	free(cmd);
}
