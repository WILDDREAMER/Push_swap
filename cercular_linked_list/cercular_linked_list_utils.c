/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cercular_linked_list_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:03:05 by ozakkare          #+#    #+#             */
/*   Updated: 2021/07/08 18:19:05 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	add_back(t_stack **head, int val)
{
	t_stack	*new;
	t_stack	*last;

	if (*head == NULL)
		return (0);
	new = malloc(sizeof(t_stack));
	last = (*head)->prev;
	last->next = new;
	(*head)->prev = new;
	new->prev = last;
	new->next = (*head);
	new->val = val;
	return (0);
}

int	push(t_stack **head, int val)
{
	t_stack	*new;

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

int	pop(t_stack **head)
{
	t_stack	*last;
	t_stack	*to_free;

	if (*head == NULL)
		return (0);
	if (stack_size(*head) == 1)
	{
		free(*head);
		*head = NULL;
		return (0);
	}
	to_free = *head;
	last = (*head)->prev;
	*head = (*head)->next;
	(*head)->prev = last;
	last->next = *head;
	free(to_free);
	return (0);
}

int	pop_last(t_stack **head)
{
	t_stack	**new_last;

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

int	get_index_of_max(t_stack *head)
{
	t_stack	*curr_node;
	int		i;
	int		index_of_max;
	int		val_of_max;

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
