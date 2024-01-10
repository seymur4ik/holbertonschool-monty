#include "monty.h"

/**
 * unknown_ins - function that handles unknown instructions
 * @line_number: line number
 * @opcode: opcode
 * @fd: file descriptor
 * @line: line
 * @stack: stack
 * Return: void
*/
void unknown_ins(size_t line_number, char *opcode,
		FILE *fd, char *line, stack_t *stack)
{
	fprintf(stderr, "L%lu: unknown instruction %s\n", line_number, opcode);
	fclose(fd);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * push_usage_error - function that handles push usage errors
 * @line_number: line number
 * @fd: file descriptor
 * @line: line
 * @stack: stack
 * Return: void
*/
void push_usage_error(size_t line_number, FILE *fd,
		char *line, stack_t **stack)
{
	fprintf(stderr, "L%lu: usage: push integer\n", line_number);
	fclose(fd);
	free(line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
