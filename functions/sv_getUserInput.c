#include "sv_shell.h"

/**
 * getUserInput - gets user input from stdin
 * @input: pointer to an array of strings
 * @size: size of the array
 *
 * Return: Nothing
 */

void getUserInput(char *input, size_t size)
{
	int read, len;

	while (1)
	{
		displayPrompt();

		/* Flush the output buffer to ensure the prompt is displayed */
		fflush(stdout);

		input = NULL;
		size = 0;

		read = getline(&input, &size, stdin);

		if (read != -1)
		{
			/* Remove the newline character if present */
			len = strlen(input);

			if (len > 0 && input[len - 1] == '\n')
				input[len - 1] = '\0';

			/*TODO: handle Input */
			printf("%s\n", input);
		}
		else
		{
			exit(1);
		}
	}
	free(input);
}

