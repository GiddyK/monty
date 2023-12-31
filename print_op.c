#include "monty.h"
/**
 * pint_op - prints the values of the stack
 * @my_stack: double pointer to the stack to print values for
 * @line_num: line no. associated  with pint opcode
 * Return: void
 */
void pint_op(stack_t **my_stack, unsigned int line_num)
{
	if (my_stack == NULL || *my_stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*my_stack)->n);
}

