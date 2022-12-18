#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _getline - this is the prompt and getline function for simple shell
 * Return: pointer to the getline data
 */

int *_getline(void)
{

	size_t n = 0;
	char *buff = NULL, *token, *delimeter = "\n";
	struct stat st;

	while (1)
	{
		buff = malloc(sizeof(char) * n);
		if (buff != NULL)
		{
			printf("emma_mavel_shell ");
			if ((getline(&buff, &n, stdin)) == -1)
				perror("Error with getline");

			token = strtok(buff, delimeter);
			if (stat(token, &st) == 0)
				printf("\n%s: FOUND. Make a call to STRINGTOKENIZATION and EXECVE\n\n", token);
			else
				printf("\n%s: NOT FOUND. Loop\n\n", token);
			if (strcmp(token, "exit") == 0)
			{
				printf("\nExisting now\n");
				token = NULL, free(token);
				buff = NULL, free(buff);
				break;
			}
		}
		token = NULL, free(token);
		buff = NULL, free(buff);
	}
	return (0);
}
