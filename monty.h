#ifndef MONTY_H
#define MONTY_H

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>

#define INSTRUCTIONS \
{ \
	{"push", push_op}, \
	{"pall", pall_op}, \
	{"pint", pint_op}, \
	{"pop", pop_top}, \
	{"rotr", last_top}, \
	{"swap", swap_top}, \
	{"rotl",top2_last}, \
	{"nop", nop_op}, \
	{"pstr", pstr_op}, \
	{"div", div_two}, \
	{"pchar", charpr_top}, \
	{"mul", ult_top}, \
	{"mod", mod_op}, \
	{"add", add_top}, \
	{"sub", sub_top}, \
	{NULL, NULL} \
}


/**
 * struct stack_s - doubly linked list representaton of stack(or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct OpcodeArgument - arguments of the current opcode
 * @mode: mode of the opcode, indicating stack mode or queue
 * @arg: argument associated with the opcode string
 *
 * Description: Global structure used to pass data btn function conveniently
 */
typedef struct OpcodeArgument
{
	int mode;
	char *arg;
} OpcodeArgument;
OpcodeArgument globalData;

/* prototypes */
void last_top(stack_t **my_stack, unsigned int line_num);
void add_top(stack_t **my_stack, unsigned int line_num);
void push_op(stack_t **my_stack, unsigned int line_num);
void pall_op(stack_t **my_stack, unsigned int line_num);
void pint_op(stack_t **my_stack, unsigned int line_num);
void swap_top(stack_t **my_stack, unsigned int line_num);
void pop_top(stack_t **my_stack, unsigned int line_num);
void nop_op(stack_t **my_stack, unsigned int line_num);
void div_two(stack_t **my_stack, unsigned int line_num);
void sub_top(stack_t **my_stack, unsigned int line_num);
void mult_top(stack_t **my_stack, unsigned int line_num);
void mod_op(stack_t **my_stack, unsigned int line_num);
void pstr_op(stack_t **my_stack, unsigned int line_num);
void charpr_top(stack_t **mystack, unsigned int line_num);
void top2_last(stack_t **my_stack, unsigned int line_num);
stack_t *addnode(stack_t **my_stack, const int n);
stack_t *add_enque(stack_t **my_stack, const int n);
void opcode_(stack_t **my_stack, char *str, unsigned int line_num);
int str_digit(char *str);
int check_number(char *str_);
void stack_free(stack_t *my_stack);
size_t display_stack(const stack_t *my_stack);
void print_error_file(char *argv);
void print_usage(void);
#endif /*MONTY_H */

