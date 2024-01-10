#include "monty.h"

/**
 * find_func - Finds the corresponding function for the given opcode
 * @opcode: The opcode to search for
 * @stack: The stack
 * @line_number: The line number
 * @fd: The file descriptor
 * @line: current line
 */
void find_func(char *opcode, stack_t **stack,
		size_t line_number, FILE *fd, char *line)
{
	int i;
	instruction_t opcodes[] = {
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{NULL, NULL}
	};
	char *value;

	if (strcmp(opcode, "push") == 0)
	{
		value = strtok(NULL, " \r\t\n");
		if (value == NULL)
			push_usage_error(line_number, fd, line, stack);
		for (i = 0; value[i] != '\0'; i++)
			if  (!isdigit(value[i]) && value[i] != '-')
				push_usage_error(line_number, fd, line, stack);
		f_push(stack, atoi(value));
		return;
	}
	if (strcmp(opcode, "nop") == 0)
		return;
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			break;
		}
	}
	if (opcodes[i].opcode == NULL)
		unknown_ins(line_number, opcode, fd, line, *stack);
}

/**
 * free_stack - function that frees a list
 * @stack: pointer to free tmp
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

