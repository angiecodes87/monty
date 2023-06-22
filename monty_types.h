#ifndef MONTY_TYPES_H
#define MONTY_TYPES_H

typedef struct stack_s {
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

#endif /* MONTY_TYPES_H */

