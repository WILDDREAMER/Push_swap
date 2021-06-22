#include "push_swap.h"

void swap(t_stack *head)
{
	int tmp;

	//only if there is more than one element
	if (head != NULL)
	{
		tmp = head->val;
		head->val = head->next->val;
		head->next->val = tmp;
	}
}

void ss(t_stack *head_a, t_stack *head_b)
{
	swap(head_a);
	swap(head_b);
}

void pa(t_stack **a, t_stack **b)
{
	push_top(a, b);
}

void pb(t_stack **a, t_stack **b)
{
	push_top(b, a);
}

int rotate(t_stack **head)
{
	if (*head == NULL)
		return 0;
	(*head) = (*head)->next;
	return 0;
}

int reverse_rotate(t_stack **head)
{
	if (*head == NULL)
		return (0);
	(*head) = (*head)->prev;
	return 0;
}

void rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void rr(t_stack **head_a, t_stack **head_b)
{
	rotate(head_a);
	rotate(head_b);
}

void push_top(t_stack **to, t_stack **from)
{
	int top;

	if (*from != NULL)
	{
		top = (*from)->val;
		push(to, top);
		pop(from);
	}
}