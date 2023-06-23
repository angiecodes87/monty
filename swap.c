#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


/**
 * swap - Swap the top two elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction in the Monty file
 *
 * Description: If the stack contains less than two elements,
 * print an error message.
 * Otherwise, swap the values of the top two elements on the stack.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	/* Free memory and exit with failure status */
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}

	/* Swap the values of the top two elements */
	int temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

