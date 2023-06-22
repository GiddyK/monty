#include "monty.h"
/**
 * add_top - add the top two elements of the stack
 * @my_stack: double pointer to the stack containing the two elements
 * @line_num: line associated with the add opcode
 * Return: void
 */
void add_top(stack_t **my_stack, unsigned int line_num)
{
	int total_sum;

	if (!my_stack || !*my_stack || !((*my_stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	total_sum = ((*my_stack)->next->n) + ((*my_stack)->n);
	pop_top(my_stack, line_num); /*deletes the top*/
	(*my_stack)->n = total_sum;
}

