#include "monty.h"

/**
 * find_func - find the correct function
 * @opcode: function code
 * Return: function and function opcode
 */
instruction_t *find_func(char *opcode)
{
	int i = 0;
	instruction_t opcodes[] = {
		{"push", f_push},
		{"pall", f_pall},
		{NULL, NULL}
	};
	instruction_t *result = NULL;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			result = malloc(sizeof(instruction_t));
			if (result == NULL)
			{
				printf("Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			result->opcode = opcodes[i].opcode;
			result->f = opcodes[i].f;
			return (result);
		}
		i++;
	}
	return (NULL);
}
