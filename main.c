#include "push_swap.h"

int add_back(t_stack **head, int val)
{
    t_stack *new;
    t_stack *last;

    //if there's no item in the stack
    if (*head == NULL)
        return 0;
	new = malloc(sizeof(t_stack));
	last = (*head)->prev;
	last->next = new;
	(*head)->prev = new;
	new->prev = last;
	new->next = (*head);
	new->val = val;
	return (0);
}

int push(t_stack **head, int val)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	new->val = val;
	if (*head == NULL)
	{
		new->next = *head;
		*head = new;
		new->prev = *head;
		return (1);
	}
	new->prev = (*head)->prev;
	new->next = *head;
	(*head)->prev = new;
	*head = new;
	return (0);
}

int pop(t_stack **head)
{
	t_stack *last;

	if (*head == NULL)
		return (0);
	last = (*head)->prev;
	*head = (*head)->next;
	last->next = *head;
	return (0);
}

int pop_last(t_stack **head)
{
	t_stack **new_last;

	if (*head == NULL)
		return (0);
	// if ((*head)->prev == *head)
	// {
	// 	pop(head);
	// 	return (0);
	// }
	// *new_last = (*head)->prev->prev;
	// (*head)->prev = *new_last;
	// (*new_last)->next = (*head);
	return (0);
}

void swap(t_stack *head)
{
	int tmp;

	//only if there is more than one element
	if (head->next != NULL)
	{
		tmp = head->val;
		head->val = head->next->val;
		head->next->val = tmp;
	}
}

void push_top(t_stack **to, t_stack **from)
{
	int top;

	if (from != NULL)
	{
		top = (*from)->val;
		push(to, top);
		pop(from);
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
void initialize(t_stack **a, t_stack **b)
{
	(*a)->next = NULL;
	(*a)->prev = NULL;
	(*b)->next = NULL;
	(*b)->prev = NULL;
}

int stack_size(t_stack *head)
{
	t_stack *curr;

	int size = 0;
	if (head == NULL)
		return 0;
	else if (head->next == head)
		return (1);
	curr = head;
	while (curr->next && curr->next != head)
	{
		size++;
		curr = curr->next;
	}
	if (curr != head)
		size++;
	return size;
}

int rotate(t_stack **head)
{
	if (*head == NULL)
		return 0;
	add_back(head, (*head)->val);
	pop(head);
	return 0;
}

int reverse_rotate(t_stack **head)
{
	int last;

	if (*head == NULL)
		return (0);
	last = (*head)->prev->val;
	pop_last(head);
	push(head, last);
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

void visualize(t_stack *a, t_stack *b)
{
	t_stack *curr_a;
	t_stack *curr_b;

	int size_a = stack_size(a);
	int size_b = stack_size(b);
	int size = (size_a > size_b) ? size_a : size_b;

	curr_a = a;
	curr_b = b;
	printf(" ----- STACK_A -----   ||   ----- STACK_B -----\n");
	for (int i = 0; i < size; i++)
	{
		printf("||        %-10s|| ~ ||        %-10s||\n", (size_a > i) ? ft_itoa(curr_a->val) : " ", (size_b > i) ? ft_itoa(curr_b->val) : " ");
		if (a && curr_a->next != NULL)
			curr_a = curr_a->next;
		if (b && curr_b->next != NULL)
			curr_b = curr_b->next;
	}
	printf("-----------------------------------------------\n");
}

int args_length(char **args)
{
	int i;

	i = 0;
	while(*args != NULL)
	{
		i++;
		args++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	t_stack *head_a;
	t_stack *head_b;
	char **args;
	int number_of_args;
	int i;

	if (argc < 2)
		return 0;
	number_of_args = 0;
	head_a = NULL;
	head_b = NULL;
	// initialize(&head_a, &head_b);
	args = NULL;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		number_of_args = args_length(args);
	}
	else
	{
		number_of_args = argc - 1;
		args = argv + 1;
	}
	i = -1;
	while (++i < number_of_args)
		push(&head_a, atoi(args[i]));
	visualize(head_a, head_b);
	return (1);
}