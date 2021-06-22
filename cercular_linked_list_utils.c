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

int get_index_of_max(t_stack *head)
{
	t_stack	*curr_node;
	int	i;
	int	index_of_max;
	int	val_of_max;

	i = 0;
	index_of_max = 0;
	curr_node = head;
	val_of_max = head->val;
	curr_node = curr_node->next;
	while (curr_node != head)
	{
		++i;
		if (curr_node->val > val_of_max)
		{
			val_of_max = curr_node->val;
			index_of_max = i;
		}
		curr_node = curr_node->next;
	}
	return (index_of_max);
}

int get_index_of_node(t_stack *head, int val)
{
	t_stack	*curr_node;
	int	i;

	if (val == head->val)
		return (0);
	i = 0;
	while (curr_node != head || i == 0)
	{
		++i;
		curr_node = curr_node->next;
		if (curr_node->val == val)
			return (i);
	}
	return (-1);
}

int get_index_of_min(t_stack *head)
{
	t_stack	*curr_node;
	int	i;
	int	index_of_min;
	int	val_of_min;

	i = 0;
	index_of_min = 0;
	curr_node = head;
	val_of_min = head->val;
	curr_node = curr_node->next;
	while (curr_node != head)
	{
		++i;
		if (curr_node->val < val_of_min)
		{
			val_of_min = curr_node->val;
			index_of_min = i;
		}
		curr_node = curr_node->next;
	}
	return (index_of_min);
}

int get_val_of_min(t_stack *head)
{
	t_stack	*curr_node;
	int	val_of_min;

	curr_node = head;
	val_of_min = head->val;
	curr_node = curr_node->next;
	while (curr_node != head)
	{
		if (curr_node->val < val_of_min)
			val_of_min = curr_node->val;
		curr_node = curr_node->next;
	}
	return (val_of_min);
}

int get_val_of_second(t_stack *head)
{
	t_stack *curr_node;
	int min_val;
	int sec_val;

	min_val = get_val_of_min(head);
	curr_node = head;
	sec_val = curr_node->val;
	curr_node = curr_node->next;
	while (curr_node != head)
	{
		if ((curr_node->val > min_val && curr_node->val < sec_val ) || (sec_val == min_val))
			sec_val = curr_node->val;
		curr_node = curr_node->next;
	}
	return (sec_val);
}