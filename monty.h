#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int is_ascii(int value);
int is_integer(const char *str);
void opcode_push(stack_t **stack, unsigned int line_number);
void opcode_pall(stack_t **stack);
void opcode_pint(stack_t **stack, unsigned int line_number);
void opcode_pop(stack_t **stack, unsigned int line_number);
void opcode_swap(stack_t **stack, unsigned int line_number);
void opcode_add(stack_t **stack, unsigned int line_number);
void opcode_nop(stack_t **stack, unsigned int line_number);
void opcode_sub(stack_t **stack, unsigned int line_number);
void opcode_div(stack_t **stack, unsigned int line_number);
void opcode_mul(stack_t **stack, unsigned int line_number);
void opcode_mod(stack_t **stack, unsigned int line_number);
void opcode_pchar(stack_t **stack, unsigned int line_number);
void opcode_pstr(stack_t **stack, unsigned int line_number);
void opcode_rotl(stack_t **stack);
void opcode_rotr(stack_t **stack);

#endif /* MONTY_H */
