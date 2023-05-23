#include "monty.h"
/**
 * opcode_add - add op code for monty
 * @stack: pointer to stack
 * @line_number: line of instruction
 *
 * Description: opcode for add instruction.
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack contains at least two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Perform the addition and update the stack */
	(*stack)->next->n += (*stack)->n;
	opcode_pop(stack, line_number);
}
