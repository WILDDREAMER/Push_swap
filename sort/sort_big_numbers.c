#include "../includes/push_swap.h"

int sort_big_numbers(t_stack **a, t_stack **b, t_instructions **instrcs)
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
            if((*b)->val >= mid)
                rotate(b);
            add_node("pa", instrcs);
            add_node("rb", instrcs);
        }
        else
        {
            rotate(a);
            add_node("sa", instrcs);
        }
    }
    visualize(*a, *b);
}