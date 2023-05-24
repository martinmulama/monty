#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file;
	char *line;
	size_t len;
	unsigned int line_number;
	stack_t *stack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line = NULL;
	len = 0;
	line_number = 1;
	stack = NULL;

	while (getline(&line, &len, file) != -1)
	{
		char *opcode = strtok(line, " \t\n");

		if (opcode != NULL && opcode[0] != '#')
		{
			if (strcmp(opcode, "push") == 0)
				opcode_push(&stack, line_number);
			else if (strcmp(opcode, "pall") == 0)
				opcode_pall(&stack);
			else if (strcmp(opcode, "pint") == 0)
				opcode_pint(&stack, line_number);
			else if (strcmp(opcode, "pop") == 0)
				opcode_pop(&stack, line_number);
			else if (strcmp(opcode, "swap") == 0)
				opcode_swap(&stack, line_number);
			else if (strcmp(opcode, "add") == 0)
				opcode_add(&stack, line_number);
			else if (strcmp(opcode, "nop") == 0)
				opcode_nop(&stack, line_number);
			else if (strcmp(opcode, "sub") == 0)
				opcode_sub(&stack, line_number);
			else if (strcmp(opcode, "div") == 0)
				opcode_div(&stack, line_number);
			else if (strcmp(opcode, "mul") == 0)
				opcode_mul(&stack, line_number);
			else if (strcmp(opcode, "mod") == 0)
				opcode_mod(&stack, line_number);
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
		line_number++;
	}
	fclose(file);
	if (line)
		free(line);
return (0);
}
