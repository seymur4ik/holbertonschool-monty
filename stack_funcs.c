#include "monty.h"

/**
 * f_push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	char *value = NULL;

	value = strtok(NULL, " \n\t\r");
	if (value == NULL || atoi(value) == 0)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(value);
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
/**
 * f_pall - prints all the values on the stack
 * @stack: pointer to the stack
 * @line_number: the line number in the file
 */
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
