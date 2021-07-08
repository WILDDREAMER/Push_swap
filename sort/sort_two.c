#include "../includes/push_swap.h"

int	sort_two(t_stack	*head, t_instructions **instrcs)
{
	int	min;
	int	max;

	if (stack_size(head) != 2)
		return (0);
	min = get_index_of_min(head);
	if (min != 0)
	{
		swap(head);
		add_node("sa", instrcs);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int	unsort_two(t_stack	*head, t_instructions **instcs)
{
	int	min;
	int	max;

	if (stack_size(head) != 2)
		return (0);
	min = get_index_of_min(head);
	if (min == 0)
	{
		swap(head);
		add_node("sb", instcs);
		return (1);
	}
	return (1);
}