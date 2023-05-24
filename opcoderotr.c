#include "monty.h"
/**
 * opcode_rotr - rotr op code for monty
 * @stack: pointer to stack
 *
 * Description: rotates the stack to the bottom.
 */
void opcode_rotr(stack_t **stack)
{
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
		return;

	while (current->next != NULL)
		current = current->next;

	current->next = *stack;
	(*stack)->prev = current;
	*stack = current;
	current->prev->next = NULL;
	current->prev = NULL;
}
