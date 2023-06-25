#include "monty.h"
#include "lists.h"

/**
 * rotl_handler - handles the rotl instruction
 * @stack: double pointer to the stack to push to
 * @NumberLine: number of the line in the file
 */

void rotl_handler(stackT **stack, unsigned int NumberLine)
{
	stackT *temp = *stack;
	int num  = 0;

	(void)NumberLine;

	if (*stack == NULL)
		return;
	temp = get_dnodeint_at_index(*stack, 0);
	num = temp->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint_end(stack, num);
}

/**
 * rotr_handler - handles the rotr instruction
 * @stack: double pointer to the stack to push to
 * @NumberLine: number of the line in the file
 */

void rotr_handler(stackT **stack, unsigned int NumberLine)
{
	stackT *temp = *stack;
	int num = 0, len = dlistint_len(*stack);

	(void)NumberLine;

	if (*stack == NULL)
		return;
	temp = get_dnodeint_at_index(*stack, len - 1);
	num = temp->n;
	delete_dnodeint_at_index(stack, len - 1);
	add_dnodeint(stack, num);
}

/**
 * stack_handler - handles the stack instruction
 * @stack: double pointer to the stack to push to
 * @NumberLine: number of the line in the file
 */

void stack_handler(stackT **stack, unsigned int NumberLine)
{
	(void)stack;
	(void)NumberLine;
	data.qflag = 0;
}


/**
 * queue_handler - handles the queue instruction
 * @stack: double pointer to the stack to push to
 * @NumberLine: number of the line in the file
 */

void queue_handler(stackT **stack, unsigned int NumberLine)
{
	(void)stack;
	(void)NumberLine;
	data.qflag = 1;
}
