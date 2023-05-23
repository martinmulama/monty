#include "monty.h"
/**
 * opcode_pint - pint op code for monty
 * @stack: pointer to stack
 * @line_number: line of instruction
 *
 * Description: opcode for pint instruction.
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Print the value at the top of the stack */
	printf("%d\n", (*stack)->n);
}
