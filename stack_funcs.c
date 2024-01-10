#include "monty.h"

/**
 * f_push - pushes an element to the stack
 * @stack: pointer to the stack
 * @value: value
 */
void f_push(stack_t **stack,  int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
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

/**
 * f_pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: the line number in the file
 * Return: void
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * f_pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: the line number in the file
 * Return: void
 */
void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * f_swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: the line number in the file
 * Return: void
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int tmp_n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp_n = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = tmp_n;
}
/**
 * f_add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: the line number in the file
 * Return: void
 */
void f_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp->next->n = tmp->next->n + tmp->n;
	*stack = tmp->next;
	free(tmp);
}
