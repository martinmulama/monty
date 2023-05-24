#include "monty.h"
/**
 * opcode_pchar - pchar op code for monty
 * @stack: pointer to stack
 * @line_number: line of instruction
 *
 * Description: prints the char at the top of the stack,followed by a new line.
 */
void opcode_pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;

	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", value);
}

