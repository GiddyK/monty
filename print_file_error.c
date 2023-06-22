#include "monty.h"
/**
 * print_error_file - prints the message of file error
 * @argv: array of arguments
 * Description: prints the message if file is not able to be opened
 * Return: void
 */
void print_error_file(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

