#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
    saved_head = *head;
	if (index == 0)
	{
		(*head) = saved_head->next;
        if (saved_head->next)
            saved_head->next->prev = NULL;
        saved_head->next = NULL;
        free(saved_head);
        return (1);
	}
	p = 0;
    tmp = *head;
	while (p < index)
	{
        if (!tmp)
            return (-1);
		tmp = tmp->next;
		p++;
	}
	tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	free(tmp);
	return (1);
}
