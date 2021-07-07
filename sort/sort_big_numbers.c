#include "../includes/push_swap.h"

int sort_big_numbers(t_stack **a, t_stack **b, t_instructions **instrcs)
{
    int min;
    int max;
    t_stack *curr;
    int size;

    size = stack_size(*a);
    min = get_val_of_min(*a);
    max = get_val_of_max(*a);
    curr = *a;
    if (curr->val == min || curr->val == max)
        curr = curr->next;
    else
    {
        pb(a, b);
		add_node("pb", instrcs);
        curr = curr->next;
    }
    while (--size >= 0)
    {
        if (curr->val != min && curr->val != max)
        {
            pb(a, b);
            add_node("pa", instrcs);
            curr = curr->next;
        }
        else
        {
            swap(*a);
            add_node("sa", instrcs);
        }
    }
    visualize(*a, *b);
}