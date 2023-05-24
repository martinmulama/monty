#include "monty.h"
/**
 * is_ascii - checks for given value
 * @value: value to check
 *
 * Description: check if a given value is within the ASCII range.
 *
 * Return: value
 */
int is_ascii(int value)
{
	return (value >= 0 && value <= 127);
}
