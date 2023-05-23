#include "monty.h"
/**
 * opcode_push - push op code for monty
 * @stack: pointer to stack
 * @line_number: line of instruction
 *
 * Description: opcode for push instruction.
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	/* Get the argument for the push opcode */
	char *arg;
	int value;
	stack_t *new_node;

	arg = strtok(NULL, " \t\n");

	/* Check if the argument exists */
	if (arg == NULL || !is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Convert the argument to an integer using atoi */
	value = atoi(arg);

	/* Create a new node for the stack */
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/* Initialize the new node */
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	/* Update the previous node, if it exists */
	if (*stack != NULL)
		(*stack)->prev = new_node;

	/* Update the stack to point to the new node */
	*stack = new_node;
}
/**
 * opcode_pall - pall opcode for monty
 * @stack: pointer to stack
 *
 * Description: opcode for pall instruction.
 */
void opcode_pall(stack_t **stack)
{
	stack_t *current = *stack;

	/* Print all values on the stack */
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

