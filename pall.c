#include "monty.h"
/**
 * pall_op - prints all tha values of the stack starting from the top
 * @my_stack: double pointer to the stack to print
 * @line_num: line no. associated with pall in the bytecodes
 * Return: void
 */
void pall_op(stack_t **my_stack, unsigned int line_num __attribute__((unused)))
{
	display_stack(*my_stack);
}

/**
 * display_stack - displays the values of the stack
 * @my_stack: the stack to display its values
 * Return: size of the stack
 */
size_t display_stack(const stack_t *my_stack)
{
	size_t stack_size = 0;

	while (my_stack)
	{
		printf("%d\n", my_stack->n);
		my_stack = my_stack->next;
		stack_size++;
	}
	return (stack_size);
}

