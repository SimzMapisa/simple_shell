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

/**
 * _strcat - concatenates strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to destination string
 */

char *_strcat(char *dest, const char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

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
