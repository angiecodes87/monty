#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * nop - Do nothing
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction in the Monty file
 *
 * Description: This opcode does nothing.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	/* Do nothing */
	(void)*stack;
	(void)line_number;
}

