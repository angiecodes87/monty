ww

/**
   * _sub - subtracts the top element of the stack from the second top element
    * @stack: pointer to the stack
     * @line_number: line number of the opcode
      */
void _sub(stack_t **stack, unsigned int line_number)
{
		if (*stack == NULL || (*stack)->next == NULL)
				{
							fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
									exit(EXIT_FAILURE);
										}

			(*stack)->next->n -= (*stack)->n;
				_pop(stack, line_number);
}

/**
   * _mul - multiplies the top two elements of the stack
    * @stack: pointer to the stack
     * @line_number: line number of the opcode
      */
void _mul(stack_t **stack, unsigned int line_number)
{
		if (*stack == NULL || (*stack)->next == NULL)
				{
							fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
									exit(EXIT_FAILURE);
										}

			(*stack)->next->n *= (*stack)->n;
				_pop(stack, line_number);
}

/**
   * _div - divides the second top element of the stack by the top element
    * @stack: pointer to the stack
     * @line_number: line number of the opcode
      */
void _div(stack_t **stack, unsigned int line_number)
{
		if (*stack == NULL || (*stack)->next == NULL)
				{
							fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
									exit(EXIT_FAILURE);
										}

			if ((*stack)->n == 0)
					{
								fprintf(stderr, "L%d: division by zero\n", line_number);
										exit(EXIT_FAILURE);
											}

				(*stack)->next->n /= (*stack)->n;
					_pop(stack, line_number);
}

/**
   * _mod - computes the remainder of the division of the second top element
    *        of the stack by the top element
     * @stack: pointer to the stack
      * @line_number: line number of the opcode
       */
void _mod(stack_t **stack, unsigned int line_number)
{
		if (*stack == NULL || (*stack)->next == NULL)
				{
							fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
									exit(EXIT_FAILURE);
										}

			if ((*stack)->n == 0)
					{
								fprintf(stderr, "L%d: division by zero\n", line_number);
										exit(EXIT_FAILURE);
											}

				(*stack)->next->n %= (*stack)->n;
					_pop(stack, line_number);
}

