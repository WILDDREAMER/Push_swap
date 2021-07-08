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
        {
            pb(a, b);
            add_node("pb", instrcs);
            if((*b)->val >= mid)
            {
                rotate(b);
                add_node("rb", instrcs);
            }
        }
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

int sort_big_numbers(t_stack **a, t_stack **b, t_instructions **instrcs)
{
    int *n_moves;
    int size;
    int siz_a;
    int first_size;
    int i;
    int j;
    int k;
    int index_curr_move;
    t_stack *cur;
    int closest;

    i = -1;
    isolate_min_max(a, b, instrcs);
    first_size = stack_size(*b);
    while (++i < first_size)
    {
        size = stack_size(*b);
        n_moves = malloc(size * sizeof(int));
        cur = *b;
        j = -1;
        while (++j < size)
        {
            closest = get_index_of_closest(*a, cur->val);
            if (closest > (stack_size(*a) / 2))
                closest = stack_size(*a) - closest;
            if (j < (size / 2))
                n_moves[j] = j + closest;
            else
                n_moves[j] = (size - j) + closest;
            cur = cur->next;
        }
        k = -1;
        index_curr_move = index_of_curr_move(n_moves, size);
        if (index_curr_move < (size / 2))
            while (++k < index_curr_move)
            {
                rotate(b);
                add_node("rb", instrcs);
            }
        else
            while (++k < (size - index_curr_move))
            {
                reverse_rotate(b);
                add_node("rrb", instrcs);
            }
        k = -1;
        closest = get_index_of_closest(*a, (*b)->val);
        size = stack_size(*a);
        if (closest < (size / 2))
            while (++k < closest)
            {
                rotate(a);
                add_node("ra", instrcs);
            }
        else
            while (++k < (size - closest))
            {
                reverse_rotate(a);
                add_node("rra", instrcs);
            }
        pa(a, b);
        add_node("pa", instrcs);
        free(n_moves);
    }
    size = stack_size(*a);
    int min_index = get_index_of_min(*a);
    int min_val = get_val_of_min(*a);
    if (min_index > (size / 2))
        while ((*a)->val != min_val)
        {
            reverse_rotate(a);
            add_node("rra", instrcs);
        }
    else
        while ((*a)->val != min_val)
        {
            rotate(a);
            add_node("ra", instrcs);
        }
}