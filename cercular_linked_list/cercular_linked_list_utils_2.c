/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cercular_linked_list_utils_2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:13:40 by ozakkare          #+#    #+#             */
/*   Updated: 2021/07/08 18:24:45 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_val_of_second_max(t_stack *head)
{
	t_stack	*curr_node;
	int		max_val;
	int		sec_val;

	max_val = get_val_of_max(head);
	curr_node = head;
	sec_val = curr_node->val;
	curr_node = curr_node->next;
	while (curr_node != head)
	{
		if ((curr_node->val < max_val && curr_node->val > sec_val)
			|| (sec_val == max_val))
			sec_val = curr_node->val;
		curr_node = curr_node->next;
	}
	return (sec_val);
}

int	delete_node(t_stack **head, int val)
{
	t_stack	*curr;

	curr = *head;
	if (curr->val == val)
	{
		curr->val = INT32_MAX;
		return (1);
	}
	else
		curr = curr->next;
	while (curr != (*head))
	{
		if (curr->val == val)
		{
			curr->val = INT32_MAX;
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}

t_stack	*create_cpy(t_stack *head)
{
	int		size;
	int		i;
	t_stack	*cpy;
	t_stack	*curr;

	cpy = NULL;
	size = stack_size(head);
	curr = head;
	i = -1;
	while (++i < size)
	{
		push(&cpy, curr->val);
		curr = curr->next;
	}
	return (cpy);
}

void	free_t_instrcs(t_instructions *stack)
{
	t_instructions	*curr;
	int				size;
	int				i;

	i = -1;
	while (stack != NULL)
	{
		curr = stack;
		stack = stack->next;
		free(curr);
	}
}

void	free_t_stack(t_stack *stack)
{
	t_stack	*curr;
	int		size;
	int		i;

	i = -1;
	size = stack_size(stack);
	while (++i < size)
	{
		curr = stack;
		stack = stack->next;
		free(curr);
		curr = NULL;
	}
}
