#include "monty.h"
/**
 * opcode_pop - pop op code for monty
 * @stack: pointer to stack
 * @line_number: line of instruction
 *
 * Description: opcode for pop instruction.
 */

void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	/* Check if the stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Remove the top element of the stack */
	top = *stack;
	*stack = (*stack)->next;

	/* Update the previous node, if it exists */
	if (*stack != NULL)
		(*stack)->prev = NULL;

	/* Free the memory of the removed node */
	free(top);
}
