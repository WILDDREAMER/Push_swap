/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:03:38 by ozakkare          #+#    #+#             */
/*   Updated: 2021/07/09 12:04:38 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	reverse_rotate(t_stack **head)
{
	if (*head == NULL)
		return (0);
	(*head) = (*head)->prev;
	return (0);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	rr(t_stack **head_a, t_stack **head_b)
{
	rotate(head_a);
	rotate(head_b);
}

void	push_top(t_stack **to, t_stack **from)
{
	int	top;

	if (*from != NULL)
	{
		top = (*from)->val;
		push(to, top);
		pop(from);
	}
}
