#include "monty.h"
/**
 * opcode_nop - push op code for monty
 * @stack: pointer to stack
 * @line_number: line of instruction
 *
 * Description: opcode for doing nothing.
 */
void opcode_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
    /* The "nop" opcode does nothing, so we simply ignore it */
}
