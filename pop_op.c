#include "monty.h"
/**
 * pop_top - removes the top element of the stack
 * @my_stack: double pointer to the stack to remove the top element
 * @line_num: line no associated with the pop opcode
 * Return: void
 */
void pop_top(stack_t **my_stack, unsigned int line_num)
{
	stack_t *temp_node = NULL; /*Node to traverser*/

	if (!my_stack || !*my_stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp_node = (*my_stack)->next;
	free(*my_stack);
	*my_stack = temp_node;

	if (!*my_stack)
		return;
	(*my_stack)->prev = NULL;
}
