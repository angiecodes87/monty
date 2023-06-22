#include "monty.h"

/**
 * _pall - prints all the values on the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode in the Monty file
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
	printf("%d\n", current->n);
	current = current->next;
	}
}


