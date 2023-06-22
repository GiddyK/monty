#include "monty.h"
/**
 * print_usage - if user does not give any file/gives more than 1 args
 * Description: prints usage message and exits
 * Return: void
 */
void print_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

