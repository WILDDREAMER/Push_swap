#include "push_swap.h"

int add_back(t_stack **head, int val)
{
    t_stack *new;
    t_stack *last;

    //if there's no item in the stack
    if (*head == NULL)
        return 0;
	new = malloc(sizeof(t_stack));
	last = (*head)->prev;
	last->next = new;
	(*head)->prev = new;
	new->prev = last;
	new->next = (*head);
	new->val = val;
	return (0);
}

int push(t_stack **head, int val)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	new->val = val;
	if (*head == NULL)
	{
		*head = new;
		new->next = *head;
		new->prev = *head;
		return (1);
	}
	new->prev = (*head)->prev;
	new->next = *head;
	(*head)->prev = new;
	new->prev->next = new;
	*head = new;
	return (0);
}

int pop(t_stack **head)
{
	t_stack *last;

	if (*head == NULL)
		return (0);
	if (stack_size(*head) == 1)
	{
		*head = NULL;
		return (0);
	}
	last = (*head)->prev;
	*head = (*head)->next;
	(*head)->prev = last;
	last->next = *head;
	return (0);
}

int pop_last(t_stack **head)
{
	t_stack **new_last;

	if (*head == NULL)
		return (0);
	if ((*head)->prev == *head)
	{
		pop(head);
		return (0);
	}
	*new_last = (*head)->prev->prev;
	(*head)->prev = *new_last;
	(*new_last)->next = (*head);
	return (0);
}
