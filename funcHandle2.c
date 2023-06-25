#include "monty.h"
#include "lists.h"

/**
 * sub_handler - handles the sub instruction
 * @stack: double pointer to the stack to push to
 * @NumberLine: number of the line in the file
 */
void sub_handler(stackT **stack, unsigned int NumberLine)
{
	int sub = 0;
	stackT *node = NULL;
	stackT *node_0 = get_dnodeint_at_index(*stack, 0);
	stackT *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SUB_FAIL, NumberLine);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	sub = node_1->n - node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, sub);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * div_handler - handles the div instruction
 * @stack: double pointer to the stack to push to
 * @NumberLine: number of the line in the file
 */
void div_handler(stackT **stack, unsigned int NumberLine)
{
	int div = 0;
	stackT *node = NULL;
	stackT *node_0 = get_dnodeint_at_index(*stack, 0);
	stackT *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, DIV_FAIL, NumberLine);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, NumberLine);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	div = node_1->n / node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, div);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul_handler - handles the mul instruction
 * @stack: double pointer to the stack to push to
 * @NumberLine: number of the line in the file
 */
void mul_handler(stackT **stack, unsigned int NumberLine)
{
	int mul = 0;
	stackT *node = NULL;
	stackT *node_0 = get_dnodeint_at_index(*stack, 0);
	stackT *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MUL_FAIL, NumberLine);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	mul = node_1->n * node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, mul);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * mod_handler - handles the mod instruction
 * @stack: double pointer to the stack to push to
 * @NumberLine: number of the line in the file
 */
void mod_handler(stackT **stack, unsigned int NumberLine)
{
	int mod = 0;
	stackT *node = NULL;
	stackT *node_0 = get_dnodeint_at_index(*stack, 0);
	stackT *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MOD_FAIL, NumberLine);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, NumberLine);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	mod = node_1->n % node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, mod);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}
