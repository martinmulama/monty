#include "monty.h"
/**
 * opcode_mod - modulud op code for monty
 * @stack: pointer to stack
 * @line_number: line of instruction
 *
 * Description: opcode for modulus instruction.
 */
void opcode_mod(stack_t **stack, unsigned int line_number)
{
	int a;
	int b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	b = (*stack)->n;
	a = (*stack)->next->n;

	if (b == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = a % b;

	opcode_pop(stack, line_number); /* Remove the top element from the stack */
}
