/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cercular_linked_list_utils_3.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:19:30 by ozakkare          #+#    #+#             */
/*   Updated: 2021/07/08 18:19:47 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_val_of_mid(t_stack *head)
{
	int		*sorted;
	t_stack	*cpy;
	int		size;
	int		min;
	int		i;

	size = stack_size(head);
	sorted = malloc(size * sizeof(int));
	cpy = create_cpy(head);
	i = -1;
	while (++i < size)
	{
		sorted[i] = get_val_of_min(cpy);
		delete_node(&cpy, sorted[i]);
	}
	i = sorted[size / 2];
	free_t_stack(cpy);
	free(sorted);
	sorted = NULL;
	return (i);
}

int	add_node(char *val, t_instructions **instrcs)
{
	t_instructions	*new;
	t_instructions	*curr;

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

int	check_second_last(t_stack **a, t_stack **b, int *stop)
{
	int	sec_min;

	sec_min = get_val_of_second(*a);
	if (*stop)
		return (0);
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
