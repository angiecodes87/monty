#include <stdlib.h>
#include <stdio.h>
#include "monty.h"
/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the instruction.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value = 0;

	/* Create a new stack node */
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	/* Free memory and exit with failure status */
	free_stack(stack);
	exit(EXIT_FAILURE);
	}

	/* Set the value and links of the new node */
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	/* If the stack is empty, set the new node as the head */
	if (*stack == NULL)
	{
	*stack = new_node;
	}
	else
	{
	/* Set the new node as the top of the stack */
	new_node->next = *stack;
	(*stack)->prev = new_node;
	*stack = new_node;
	}
}
/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the instruction.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	/* Print all values on the stack */
	stack_t *current = *stack;
	while (current != NULL)
	{
	/* Print the value of current node */
	printf("%d\n", current->n);
	current = current->next;
	}
}

