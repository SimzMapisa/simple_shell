#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
int _putchar(char c);
int displayPrompt(void);
int handleUserInput(char *argv[]);
int _strcmp(const char *str1, const char *str2);
int _strlen(const char *str);
char *_strcat(char *dest, const char *src);
int checktabsornewline(char *str);

#endif
