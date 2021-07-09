#include "./includes/push_swap.h"

void	swap(t_stack *head)
{
	int	tmp;

	if (head != NULL)
	{
		tmp = head->val;
		head->val = head->next->val;
		head->next->val = tmp;
	}
}

void	ss(t_stack *head_a, t_stack *head_b)
{
	swap(head_a);
	swap(head_b);
}

void	pa(t_stack **a, t_stack **b)
{
	push_top(a, b);
}

void	pb(t_stack **a, t_stack **b)
{
	push_top(b, a);
}

int	rotate(t_stack **head)
{
	if (*head == NULL)
		return (0);
	(*head) = (*head)->next;
	return (0);
}
