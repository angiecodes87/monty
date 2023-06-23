#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


/**
 * pop - Remove the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction in the Monty file
 *
 * Description: If the stack is empty, print an error message.
 * Otherwise, remove the top element from the stack.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	/* Free memory and exit with failure status */
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}

	/* Remove the top element from the stack */
	stack_t *temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	(*stack)->prev = NULL;
	free(temp);
}

