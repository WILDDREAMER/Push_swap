#include "./includes/push_swap.h"

int	stack_size(t_stack *head)
{
	t_stack	*curr;
	int		size;

	size = 0;
	if (head == NULL)
		return (0);
	curr = head;
	while (curr->next != head)
	{
		size++;
		curr = curr->next;
	}
	size++;
	return (size);
}

int	args_length(char **args)
{
	int	i;

	i = 0;
	while (*args != NULL)
	{
		i++;
		args++;
	}
	return (i);
}
