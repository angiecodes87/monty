#include "monty.h"
/**
 * read_file - reads a bytecode file and runs commands
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
 */
void read_file(char *filename, stack_t **stack);
instruct_func get_op_func(char *str);
int isnumber(char *str);
char *parse_line(char *line, stack_t **stack, unsigned int line_number);

void read_file(char *filename, stack_t **stack)
{
	char *line;
	size_t i = 0;
	int line_count = 1;
	instruct_func s;
	int check;
	int read;

	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
	}

	while ((read = getline(&var_global.buffer, &i, file)) != -1)
	{
	line = parse_line(var_global.buffer, stack, line_count);
	if (line == NULL || line[0] == '#')
	{
	line_count++;
	continue;
	}
	s = get_op_func(line);
	if (s == NULL)
	{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
	exit(EXIT_FAILURE);
	}


	s(stack, line_count);
	line_count++;
	}

	free(var_global.buffer);
	check = fclose(file);
	if (check == -1)
	exit(-1);
}
/**
 * get_op_func -  checks opcode and returns the correct function
 * @str: the opcode
 * Return: returns a functions, or NULL on failure
 */

instruct_func get_op_func(char *str)
{
	int i = 0;

	instruction_t instruct[] = {
	{"push", _push},
	{"pall", _pall},
	{"pint", _pint},
	{"pop", _pop},
	{"swap", _swap},
	{"add", _add},
	{"nop", _nop},
	{"sub", _sub},
	{"mul", _mul},
	{"div", _div},
	{"mod", _mod},
	{"pchar", _pchar},
	{"pstr", _pstr},
	{"rotl", _rotl},
	{"rotr", _rotr},
	{NULL, NULL},
	};

	while (instruct[i].opcode != NULL)
	{
	if (strcmp(instruct[i].opcode, str) == 0)
	return (instruct[i].f);
	i++;
	}

	return (NULL);
}
/**
 * isnumber - checks if a string is a number
 * @str: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int isnumber(char *str)
{
	if (str == NULL)
	return (0);

	int i = 0;

	if (str[i] == '-')
	i++;

	while (str[i] != '\0')
	{
	if (!isdigit(str[i]))
	return (0);
	i++;
	}

	return (1);
}
/**
 * parse_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 * @stack: pointer to the head of the stack
 * @line_number: the current line number
 * Return: returns the opcode or null on failure
 */
char *parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *op_code, *push, *arg;
	(void)stack;

	push = "push";
	op_code = strtok(line, " \t\n");
	if (op_code == NULL)
	return (NULL);

	if (strcmp(op_code, push) == 0)
	{
	arg = strtok(NULL, " \t\n");
	if (arg == NULL || !isnumber(arg))
	{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
	}
	var_global.push_arg = atoi(arg);
	}

	return (op_code);
}
/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: Exit status of the program
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
	fprintf(stderr, "Usage: %s filename\n", argv[0]);
	return (EXIT_FAILURE);
	}
	stack_t *stack = NULL;

	read_file(argv[1], &stack);

	return (EXIT_SUCCESS);
}

