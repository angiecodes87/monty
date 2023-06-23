#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * add - Add the top two elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction in the Monty file
 *
 * Description: If the stack contains less than two elements,
 * print an error message.
 * Otherwise, add the top two elements on the stack and replace
 * them with the result.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	/* Free memory and exit with failure status */
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}

	/* Add the top two elements and replace them with the result */
	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number);
}

