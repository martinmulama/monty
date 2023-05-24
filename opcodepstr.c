#include "monty.h"
/**
 * opcode_pstr - pstr op code for monty
 * @stack: pointer to stack
 * @line_number: line of instruction
 *
 * Description: prints the string starting at the top of the stack
 */
void opcode_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;

	while (current != NULL && current->n != 0 && is_ascii(current->n))
	{
		if (current->n < 0 || current->n > 127)
		{
			fprintf(stderr, "L%u: can't pstr, value out of range\n", line_number);
			free(stack);
			exit(EXIT_FAILURE);
		}

		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}
