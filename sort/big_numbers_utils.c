/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_numbers_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 19:46:15 by ozakkare          #+#    #+#             */
/*   Updated: 2021/07/08 19:46:34 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_index_of_closest(t_stack *head, int val)
{
    int size;
    int i;
    int result;
    int result_val;
    t_stack *curr;

    i = -1;
    curr = head;
    size = stack_size(head);
    result_val = get_val_of_max(head);
    result = get_index_of_max(head);
    while (++i < size)
    {
        if (val < curr->val && curr->val < result_val)
        {
            result_val = curr->val;
            result = i;
        }
        curr = curr->next;
    }
    return (result);
}

void not_min_max(t_stack **a, t_stack **b, t_instructions **instrcs, int mid)
{
    pb(a, b);
    add_node("pb", instrcs);
    if ((*b)->val >= mid)
    {
        rotate(b);
        add_node("rb", instrcs);
    }
}

void isolate_min_max(t_stack **a, t_stack **b, t_instructions **instrcs)
{
    int min;
    int max;
    int mid;
    int size;

    size = stack_size(*a);
    min = get_val_of_min(*a);
    max = get_val_of_max(*a);
    mid = get_val_of_mid(*a);
    while (--size >= 0)
    {
        if ((*a)->val != min && (*a)->val != max)
            not_min_max(a, b, instrcs, mid);
        else
        {
            rotate(a);
            add_node("ra", instrcs);
        }
    }
    if ((*a)->val < (*a)->next->val)
    {
        rotate(a);
        add_node("ra", instrcs);
    }
}

int index_of_curr_move(int *tab, int size)
{
    int min_index;
    int min_val;
    int i;

    min_val = tab[0];
    min_index = 0;
    i = 0;
    while (++i < size)
    {
        if (tab[i] < min_val)
        {
            min_index = i;
            min_val = tab[i];
        }
    }
    return (min_index);
}

void calculate_instrcs(t_big_numbers *vars, t_stack **a, t_stack **b)
{
    vars->closest = get_index_of_closest(*a, vars->cur->val);
    vars->size_a = stack_size(*a);
    if (vars->closest > (vars->size_a / 2))
        vars->closest = vars->size_a - vars->closest;
    if (vars->j < (vars->size / 2))
        vars->n_moves[vars->j] = vars->j + vars->closest;
    else
        vars->n_moves[vars->j] = (vars->size - vars->j) + vars->closest;
    vars->cur = vars->cur->next;
}