#include "monty.h"
/**
 * main - Entyr point
 * @argc: count of args
 * @argv: args
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	char *line = NULL, *opcode = NULL;
	int line_number = 0;
	instruction_t *ins = NULL;
	size_t len = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, fd) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n\t\r");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		ins = find_func(opcode);
		if (ins == NULL)
		{
			printf("L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		ins->f(&stack, line_number);
	}
	return (0);
}
