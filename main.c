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
	size_t len = 0, line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, fd) != -1)
	{
		line_number++;
		opcode = strtok(line, " \r\t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		find_func(opcode, &stack, line_number, fd, line);
		free(line);
		line = NULL;
	}
	free_stack(stack);
	free(line);
	fclose(fd);
	return (0);
}
