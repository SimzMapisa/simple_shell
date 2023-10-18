#include "sv_shell.h"

/**
 * _strcpy - copies a string to another file
 * @dest: destination file
 * @src: source file
 * Return: a pointer to destination file
 */

char *_strcpy(char *dest, const char *src)
{
	int i, len;

	len = _strlen(src);

	if (_strlen(dest) != len)
		return (NULL);

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
