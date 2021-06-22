#include "push_swap.h"

int stack_size(t_stack *head)
{
	t_stack *curr;

	int size = 0;
	if (head == NULL)
		return 0;
	curr = head;
	while (curr->next != head)
	{
		size++;
		curr = curr->next;
	}
	size++;
	return size;
}

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
		*head = new;
		new->next = *head;
		new->prev = *head;
		return (1);
	}
	new->prev = (*head)->prev;
	new->next = *head;
	(*head)->prev = new;
	new->prev->next = new;
	*head = new;
	return (0);
}

int pop(t_stack **head)
{
	t_stack *last;

	if (*head == NULL)
		return (0);
	if (stack_size(*head) == 1)
	{
		*head = NULL;
		return (0);
	}
	last = (*head)->prev;
	*head = (*head)->next;
	(*head)->prev = last;
	last->next = *head;
	return (0);
}

int pop_last(t_stack **head)
{
	t_stack **new_last;

	if (*head == NULL)
		return (0);
	if ((*head)->prev == *head)
	{
		pop(head);
		return (0);
	}
	*new_last = (*head)->prev->prev;
	(*head)->prev = *new_last;
	(*new_last)->next = (*head);
	return (0);
}

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

void visualize(t_stack *a, t_stack *b)
{
	t_stack *curr_a;
	t_stack *curr_b;

	int size_a = stack_size(a);
	int size_b = stack_size(b);
	int size = (size_a > size_b) ? size_a : size_b;

	curr_a = a;
	curr_b = b;
	printf("%s", YEL);
	printf(" ----- STACK_A -----   ||   ----- STACK_B -----\n");
	write(1, WHT, ft_strlen(WHT));
	for (int i = 0; i < size; i++)
	{
		printf("%s||        %-10s|| ~ ||        %-10s||\n", BLU, (size_a > i) ? ft_itoa(curr_a->val) : " ", (size_b > i) ? ft_itoa(curr_b->val) : " ");
		if (a && curr_a->next != NULL)
			curr_a = curr_a->next;
		if (b && curr_b->next != NULL)
			curr_b = curr_b->next;
	}
	printf("%s", YEL);
	printf("-----------------------------------------------\n");
	write(1, WHT, ft_strlen(WHT));
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

int handle_input(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "sa"))
		swap(*a);
	else if (!ft_strcmp(line, "sb"))
		swap(*b);
	else if (!ft_strcmp(line, "ss"))
		ss(*a, *b);
	else if (!ft_strcmp(line, "pa"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb"))
		pb(a, b);
	else if (!ft_strcmp(line, "ra"))
		rotate(a);
	else if (!ft_strcmp(line, "rb"))
		rotate(b);
	else if (!ft_strcmp(line, "rr"))
		rr(a, b);
	else if (!ft_strcmp(line, "rra"))
		reverse_rotate(a);
	else if (!ft_strcmp(line, "rrb"))
		reverse_rotate(b);
	else if (!ft_strcmp(line, "rrr"))
		rrr(a, b);
	else
	{
		write(1, RED, ft_strlen(RED));
		write(1, "SYNTAX ERROR\n", 13);
		write(1, WHT, ft_strlen(WHT));
		return (0);
	}
	return (1);
}

char *checker(t_stack *a)
{
	t_stack *curr_node;
	int		curr_val;

	curr_val = a->val;
	curr_node = a->next;
	while(curr_node != a)
	{
		if (curr_val > curr_node->val)
			return ("\e[1;31mKO\n");
		curr_val = curr_node->val;
		curr_node = curr_node->next;
	}
	return ("\e[1;32mOK\n");
}

int main(int argc, char **argv)
{
	t_stack *head_a;
	t_stack *head_b;
	char **args;
	char *line;
	int number_of_args;
	int i;

	if (argc < 2)
		return 0;
	number_of_args = 0;
	head_a = NULL;
	head_b = NULL;
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
	i = number_of_args;
	while (--i >= 0)
		push(&head_a, atoi(args[i]));
	while (get_next_line(0, &line) > 0)
	{	
		if (!handle_input(&head_a, &head_b, line))
			return (0);
		visualize(head_a, head_b);
	}
	printf("%s",checker(head_a));
	return (1);
}