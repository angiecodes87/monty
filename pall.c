#include "monty.h"
/**
 * _push - pushes an element to the stack
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");
	int num;

	if (!arg || !isdigit(*arg))
	{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
	}

	num = atoi(arg);
	push(stack, num);
}

/**
 * _pall - prints all the values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;

	while (tmp)
	{
	printf("%d\n", tmp->n);
	tmp = tmp->next;
	}
}

