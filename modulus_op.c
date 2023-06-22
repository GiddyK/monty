#include "monty.h"
/**
 * mod_op - gives the remainder of division
 * @my_stack: double pointer to the stack containing the two elements
 * @line_num: line no associated with the mod opcode
 * Return: void
 */
void mod_op(stack_t **my_stack, unsigned int line_num)
{
	int mod_result;

	if (!my_stack || !*my_stack || !((*my_stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*my_stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}

	mod_result = ((*my_stack)->next->n) % ((*my_stack)->n);
	pop_top(my_stack, line_num);
	(*my_stack)->n = mod_result;
}

