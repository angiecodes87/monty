#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode in the Monty file
 */
void _push(stack_t **stack, unsigned int line_number)
{

	int value = atoi(var_global.buffer);

	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	free(var_global.buffer);
	fclose(var_global.file);
	free_dlistint(*stack);
	exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	(*stack)->prev = new_node;

	*stack = new_node;
}


