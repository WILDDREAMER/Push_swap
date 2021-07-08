/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:10:37 by ozakkare          #+#    #+#             */
/*   Updated: 2021/07/08 21:11:45 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	help_optimize(t_instructions **curr)
{
	if ((*curr)->next && ((!ft_strcmp((*curr)->val, "rra")
				&& !ft_strcmp((*curr)->next->val, "rrb"))
			|| (!ft_strcmp((*curr)->next->val, "rra")
				&& !ft_strcmp((*curr)->val, "rrb"))))
	{
		write(1, "rrr\n", 4);
		(*curr) = (*curr)->next->next;
	}
	else
	{
		write(1, (*curr)->val, ft_strlen((*curr)->val));
		write(1, "\n", 1);
		(*curr) = (*curr)->next;
	}
}

int	optimize_instrucs(t_instructions **head)
{
	t_instructions	*curr;

	curr = *head;
	while (curr)
	{
		if (curr->next
			&& ((!ft_strcmp(curr->val, "ra")
					&& !ft_strcmp(curr->next->val, "rb"))
				|| (!ft_strcmp(curr->next->val, "ra")
					&& !ft_strcmp(curr->val, "rb"))))
		{
			write(1, "rr\n", 3);
			curr = curr->next->next;
		}
		else
			help_optimize(&curr);
	}
	return (1);
}

void	free_double_pointer(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}
