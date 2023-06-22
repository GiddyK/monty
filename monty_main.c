#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * main - code to test the monty program
 * @argv: array of arguments passed to the program
 * @argc: size of arguments(counter)
 * Return: nothin
 */
int main(int argc, char **argv)
{
	int status = 0;
	char *string = NULL;
	stack_t *my_stack = NULL;
	size_t bufferlen = 0;
	FILE *file;
	unsigned int line_num = 1;
	char *buffer = NULL;

	globalData.mode = 1; /*stack*/
	if (argc != 2)
		print_usage();

	file = fopen(argv[1], "r");

	if (!file)
		print_error_file(argv[1]);

	while ((getline(&buffer, &bufferlen, file)) != (-1))
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_num++;
			continue;
		}
		string = strtok(buffer, " \t\n");
		if (!string || *string == '#')
		{
			line_num++;
			continue;
		}
		globalData.arg = strtok(NULL, " \t\n");
		opcode_(&my_stack, string, line_num);
		line_num++;
	}
	free(buffer);
	stack_free(my_stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}


