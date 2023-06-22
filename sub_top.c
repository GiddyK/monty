#include "monty.h"
/**
 * sub_top - subtracts two elements of the stack
 * @my_stack: double pointer to the stack containing the 2 elements
 * @line_num: line no. associated with the sub opcode
 * Return: void
 */
void sub_top(stack_t **my_stack, unsigned int line_num)
{
	int total_sum;

	if (my_stack == NULL || *my_stack == NULL || (*my_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	total_sum = ((*my_stack)->next->n) - ((*my_stack)->n);
	pop_top(my_stack, line_num); /*deleting the top most node*/
	(*my_stack)->n = total_sum;
}

