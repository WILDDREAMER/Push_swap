#include "../includes/push_swap.h"

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
	t_stack *curr_node;
	int i;
	int index_of_max;
	int val_of_max;

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
	t_stack *curr_node;
	int i;

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
	t_stack *curr_node;
	int i;
	int index_of_min;
	int val_of_min;

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
	t_stack *curr_node;
	int val_of_min;

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

int get_val_of_max(t_stack *head)
{
	t_stack *curr_node;
	int val_of_max;

	curr_node = head;
	val_of_max = head->val;
	curr_node = curr_node->next;
	while (curr_node != head)
	{
		if (curr_node->val > val_of_max)
			val_of_max = curr_node->val;
		curr_node = curr_node->next;
	}
	return (val_of_max);
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
		if ((curr_node->val > min_val && curr_node->val < sec_val) || (sec_val == min_val))
			sec_val = curr_node->val;
		curr_node = curr_node->next;
	}
	return (sec_val);
}

int get_val_of_second_max(t_stack *head)
{
	t_stack *curr_node;
	int max_val;
	int sec_val;

	max_val = get_val_of_max(head);
	curr_node = head;
	sec_val = curr_node->val;
	curr_node = curr_node->next;
	while (curr_node != head)
	{
		if ((curr_node->val < max_val && curr_node->val > sec_val) || (sec_val == max_val))
			sec_val = curr_node->val;
		curr_node = curr_node->next;
	}
	return (sec_val);
}

int delete_node(t_stack **head, int val)
{
	t_stack *curr;

	curr = *head;
	if (curr->val == val)
	{
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		(*head) = (*head)->next;
		return (1);
	}
	else
		curr = curr->next;
	while (curr != (*head))
	{
		if (curr->val == val)
		{
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}

int get_val_of_mid(t_stack *head)
{
	int *sorted;
	int size;
	int min;
	int i;

	size = stack_size(head);
	sorted = malloc(size * sizeof(int));
	i = -1;
	while (++i < size)
	{
		sorted[i] = get_val_of_min(head);
		delete_node(&head, sorted[i]);
	}
	return (sorted[size / 2]);
}

int	add_node(char *val, t_instructions **instrcs)
{
	t_instructions *new;
	t_instructions *curr;

	curr = (*instrcs);
	new = malloc(sizeof(t_instructions));
	new->val = val;
	new->next = NULL;
	if ((*instrcs) == NULL)
	{
		(*instrcs) = new;
		return (0);
	}
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	return (1);
}

int check_second_last(t_stack **a, t_stack **b, int *stop)
{
	int sec_min;

	sec_min = get_val_of_second(*a);
	if (*stop)
		return(0);
	if (sec_min == (*a)->prev->val)
	{
		write(1, "rra\n", 4);
		reverse_rotate(a);
		write(1, "pb\n", 3);
		pb(a, b);
		*stop = 1;
		return (1);
	}
	return (0);
}
