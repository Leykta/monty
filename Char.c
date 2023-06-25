#include "monty.h"
#include "lists.h"

/**
 * pchar_handler - handles the pchar instruction
 * @stack: double pointer to the stack to push to
 * @NumberLine: number of the line in the file
 */
void pchar_handler(stackT **stack, unsigned int NumberLine)
{
	stackT *node = *stack;

	if (!node)
	{
		dprintf(STDERR_FILENO, PCHAR_FAIL, NumberLine);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (node->n < 0 || node->n > 127)
	{
		dprintf(STDERR_FILENO, PCHAR_RANGE, NumberLine);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	putchar(node->n);
	putchar('\n');
}

/**
 * pstr_handler - handles the pstr instruction
 * @stack: double pointer to the stack to push to
 * @NumberLine: number of the line in the file
 */
void pstr_handler(stackT **stack, unsigned int NumberLine)
{
	stackT *node = *stack;

	(void)NumberLine;

	if (!node)
	{
		putchar('\n');
		return;
	}

	while (node && node->n != 0 && node->n >= 0 && node->n <= 127)
	{
		putchar(node->n);
		node = node->aft;
	}

	putchar('\n');
}
