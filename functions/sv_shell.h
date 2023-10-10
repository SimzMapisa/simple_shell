#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int _putchar(char c);
int displayPrompt(void);
void getUserInput(char *input, size_t size);

#endif
