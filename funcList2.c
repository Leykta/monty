#include "monty.h"
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a node at a given index
 * in a doubly linked list
 * @h: double pointer to the list
 * @idx: index of the node to insert
 * @n: data to insert
 *
 * Return: address of the new node, or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i;
	dlistint_t *new;
	dlistint_t *temp = *h;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			if (temp->aft == NULL)
				return (add_dnodeint_end(h, n));
			new = malloc(sizeof(dlistint_t));
			if (!new || !h)
				return (NULL);
			new->n = n;
			new->aft = NULL;
			new->aft = temp->aft;
			new->bef = temp;
			temp->aft->bef = new;
			temp->aft = new;
			return (new);
		}
		else
			temp = temp->aft;
	}

	return (NULL);
}

/**
 * add_dnodeint_end - adds a new node at the end of a doubly linked list
 * @head: double pointer to the list
 * @n: data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *temp = *head;

	if (!head)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->aft = NULL;

	if (*head == NULL)
	{
		new->bef = NULL;
		*head = new;
		return (new);
	}

	while (temp->aft)
		temp = temp->aft;

	temp->aft = new;
	new->bef = temp;

	return (new);
}

/**
 * free_dlistint - frees a doubly linked list
 * @head: pointer to the list to free
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head)
	{
		temp = head->aft;
		free(head);
		head = temp;
	}
}
