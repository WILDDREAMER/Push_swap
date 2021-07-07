#include "../includes/push_swap.h"

int	sort_three(t_stack	*head, t_instructions **instrcs)
{
	int min;
	int max;
	
	if (stack_size(head) != 3)
		return (0);
	min = get_index_of_min(head);
	max = get_index_of_max(head);
	if ((min == 0) && (max == 2))
		return(1);
	else if ((min == 2) && (max == 0))
	{
		add_node("ra", instrcs);
		add_node("sa", instrcs);
		return(1);
	}
	else if ((min == 2) && (max == 1))
	{
		add_node("rra", instrcs);
		return(1);
	}
	else if ((min == 1) && (max == 0))
	{
		add_node("ra", instrcs);
		return(1);
	}
	else if ((min == 0) && (max == 1))
	{
		add_node("rra", instrcs);
		add_node("sa", instrcs);
		return(1);
	}
	else if ((min == 1) && (max == 2))
	{
		add_node("sa", instrcs);
		return(1);
	}
	return(0);
}