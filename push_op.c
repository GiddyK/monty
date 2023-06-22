#include "monty.h"
/**
 * push_op - pushes an element on the stack
 * @my_stack: double pointer to the stack
 * @line_num: the line number, visibility of errors
 * Return: void
 */
void push_op(stack_t **my_stack, unsigned int line_num)
{
	char *f = globalData.arg;

	if ((str_digit(f)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (globalData.mode == 1) /*1 for stack ,0 for queue*/
	{
		if (!nodeadd(my_stack, atoi(globalData.arg)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!enqueue_(my_stack, atoi(globalData.arg)))
		{
			exit(EXIT_FAILURE);
		}
	}
}

