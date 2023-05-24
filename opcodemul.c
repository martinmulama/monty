#include "monty.h"
/**
 * opcode_mul - multiplication op code for monty
 * @stack: pointer to stack
 * @line_number: line of instruction
 *
 * Description: opcode for multiply instruction.
 */
void opcode_mul(stack_t **stack, unsigned int line_number)
{
	int a;
	int b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	b = (*stack)->n;
	a = (*stack)->next->n;

	(*stack)->next->n = a * b;

	opcode_pop(stack, line_number); /* Remove the top element from the stack */
}
