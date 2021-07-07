#include "../includes/push_swap.h"

int	sort_five(t_stack	**a, t_stack **b, t_instructions **instrcs)
{
	int min_index;
	int min_val;
	int stop_checking_for_second;
	int i;
	int j;
	int sec_min;

	if (stack_size(*a) != 5)
		return (0);
		
	if((*a)->val == get_val_of_max(*a) && (*a)->next->val == get_val_of_second_max(*a))
	{
		swap(*a);
		add_node("sa", instrcs);
	}
	sec_min = get_val_of_second(*a);
	i = 0;
	stop_checking_for_second = 0;
	while (++i <= 2)
	{
		i += check_second_last(a, b, &stop_checking_for_second);
		min_index = get_index_of_min(*a);
		min_val = get_val_of_min(*a);
		if ((stack_size(*a) - min_index) >= 3)
		{
			while (--min_index >= 0)
			{
				if (sec_min == (*a)->val && !stop_checking_for_second )
				{
					add_node("pb", instrcs);
					pb(a, b);
					--min_index;
					++i;
					stop_checking_for_second = 1;
				}
				if (min_val != (*a)->val)
				{
					add_node("ra", instrcs);
					rotate(a);
				}
			}
			add_node("pb", instrcs);
			pb(a, b);
			stop_checking_for_second = 1;
		}
		else
		{
			while (++min_index <= 5)
			{
				if (i == 2)
					++min_index;
				if (check_second_last(a, b, &stop_checking_for_second))
				{
					++i;
					++min_index;
				}
				add_node("rra", instrcs);
				reverse_rotate(a);
			}
			add_node("pb", instrcs);
			pb(a, b);
			stop_checking_for_second = 1;
		}
	}
	unsort_two(*b, instrcs);
	sort_three(*a, instrcs);
	add_node("pa", instrcs);
	add_node("pa", instrcs);
	pa(a, b);
	pa(a, b);
	return(0);
}