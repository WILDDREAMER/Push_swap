/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cercular_linked_list_utils_1.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:07:01 by ozakkare          #+#    #+#             */
/*   Updated: 2021/07/08 18:22:23 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_index_of_node(t_stack *head, int val)
{
	t_stack	*curr_node;
	int		i;

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

int	get_index_of_min(t_stack *head)
{
	t_stack	*curr_node;
	int		i;
	int		index_of_min;
	int		val_of_min;

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

int	get_val_of_min(t_stack *head)
{
	t_stack	*curr_node;
	int		val_of_min;

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

int	get_val_of_max(t_stack *head)
{
	t_stack	*curr_node;
	int		val_of_max;

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

int	get_val_of_second(t_stack *head)
{
	t_stack	*curr_node;
	int		min_val;
	int		sec_val;

	min_val = get_val_of_min(head);
	curr_node = head;
	sec_val = curr_node->val;
	curr_node = curr_node->next;
	while (curr_node != head)
	{
		if ((curr_node->val > min_val && curr_node->val < sec_val)
			|| (sec_val == min_val))
			sec_val = curr_node->val;
		curr_node = curr_node->next;
	}
	return (sec_val);
}
