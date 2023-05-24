#include "monty.h"
/**
 * opcode_sub - sub op code for monty
 * @stack: pointer to stack
 * @line_number: line of instruction
 *
 * Description: opcode for sub instruction.
 */
void opcode_sub(stack_t **stack, unsigned int line_number)
{
	int b;
	int a;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	b = (*stack)->n;
	a = (*stack)->next->n;

	(*stack)->next->n = a - b;

	opcode_pop(stack, line_number);
}
