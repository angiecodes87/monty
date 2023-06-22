#include "monty.h"

/**
 * _pstr - prints the string contained in the stack
 * @stack: pointer to the stack
 * @line_number: the line number of the opcode
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int c = 0;

	(void)line_number;

	while (tmp)
	{
	c = tmp->n;
	if (c == 0 || _isalpha(c) == 0)
	break;
	putchar(c);
	tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * _rotl - rotates the stack to the left, moving the top element to the bottom
 * @stack: pointer to the stack
 * @line_number: the line number of the opcode
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;
	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
	return;

	aux1 = runner->n;

	while (runner->next)
	{
	runner = runner->next;
	runner->prev->n = runner->n;
	}

	runner->n = aux1;
}

/**
 * _rotr - rotates the stack to the right, moving the bottom element to the top
 * @stack: pointer to the stack
 * @line_number: the line number of the opcode
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;
	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
	return;

	while (runner->next)
	runner = runner->next;

	aux1 = runner->n;

	while (runner->prev)
	{
	runner = runner->prev;
	runner->next->n = runner->n;
	}

	runner->n = aux1;
}

