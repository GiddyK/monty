#include "monty.h"
/**
 * div_two - divides the two elements of the stack
 * @my_stack: double pointer to the stack containing the two elements
 * @line_num: line no. associated with the div opcode
 * Return: void
 */
void div_two(stack_t **my_stack, unsigned int line_num)
{
	int quotient_rslt;

	if (!my_stack || !*my_stack || !((*my_stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (((*my_stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
		;
		return;
	}
	quotient_rslt = ((*my_stack)->next->n) / ((*my_stack)->n);
	pop_top(my_stack, line_num);
	(*my_stack)->n = quotient_rslt;
}

