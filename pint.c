#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pint - Print the value at the top of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction in the Monty file
 *
 * Description: If the stack is empty, print an error message.
 * Otherwise, print the value at the top of the stack followed by a new line.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	/* Free memory and exit with failure status */
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

