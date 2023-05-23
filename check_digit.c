#include "monty.h"
/**
 * is_integer - checks if inout is an integer
 * @str: pointer to string input
 * Description: checks wheter the input is an integer.
 *
 * Return: Always 0 (Success)
 */
int is_integer(const char *str)
{
	int i;

	if (str == NULL || *str == '\0')
		return (0);

	i = 0;

	if (str[0] == '-' || str[0] == '+')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}
