#include "monty.h"
/**
 *mult_top - multiplies two elements of a stack
 * @my_stack: double pointer to the stack containing the 2 elements
 * @line_num: line no. associated with the mul opcode
 * Return: void
 */
void mult_top(stack_t **my_stack, unsigned int line_num)
{
	int product_;

	if (!my_stack || !*my_stack || !((*my_stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	product_ = ((*my_stack)->next->n) * ((*my_stack)->n);
	pop_top(my_stack, line_num);
	(*my_stack)->n = product_;
}

