#include "monty.h"
/**
 * opcode_swap - swap op code for monty
 * @stack: pointer to stack
 * @line_number: line of instruction
 *
 * Description: opcode for swap instruction.
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	/* Check if the stack contains at least two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Swap the top two elements of the stack */
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
