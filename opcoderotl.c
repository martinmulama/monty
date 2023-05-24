#include "monty.h"
/**
 * opcode_rotl - rotl op code for monty
 * @stack: pointer to stack
 *
 * Description: rotates the stack to the top.
 */
void opcode_rotl(stack_t **stack)
{
	stack_t *current;

	current = *stack;

	if (current == NULL || current->next == NULL)
		return;

	while (current->next != NULL)
		current = current->next;

	current->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	current->next->next = NULL;
	current->next->prev = current;
}
