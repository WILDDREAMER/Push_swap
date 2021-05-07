#include "push_swap.h"

void push(t_stack *head, int val)
{
    t_stack *new;
    t_stack *top;

    //if there's no item in the stack
    if (head->next == NULL)
    {
        head->val = val;
        head->prev = head;
        head->next = head;
    }

    else
    {
        new = malloc(sizeof(t_stack));
        top = head->prev;
        top->next = new;
        head->prev = new;
        new->prev = top;
        new->next = head;
        new->val = val;
    }
}

int pop(t_stack **head, int val)
{
    t_stack *curr;

    curr = *head;
    if ((*head)->next == *head)
    {
        (*head)->next = NULL;
        (*head)->prev = NULL;
        return (0);
    }

    //if the target is the head we need to keep the head but change it's value
    if ((*head)->val == val)
    {
        (*head)->prev->next = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        *head = (*head)->next;
        return val;
    }
    //loop over the stack until we find our value
    while (curr->val != val && curr->next != *head)
        curr = curr->next;

    if (curr->val == val)
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        return (val);
    }
    return (0);
}

void swap(t_stack *head)
{
    int tmp;
    t_stack *top;

    //if there is more than one element
    if (head->next != head && head->next != NULL)
    {
        top = head->prev;
        tmp = top->val;
        top->val = top->prev->val;
        top->prev->val = tmp;
    }
}

void push_top(t_stack *to, t_stack *from)
{
    int top;

    if (from->next != NULL)
    {
        top = from->prev->val;
        push(to, top);
        pop(&from, top);
    }
}

void ss(t_stack *head_a, t_stack *head_b)
{
    swap(head_a);
    swap(head_b);
}

void pa(t_stack *a, t_stack *b)
{
    push_top(a, b);
}

void pb(t_stack *a, t_stack *b)
{
    push_top(b, a);
}
void initialize(t_stack *a, t_stack *b)
{
    a->next = NULL;
    a->prev = NULL;
    b->next = NULL;
    b->prev = NULL;
}

int stack_size(t_stack *head)
{
    t_stack *curr;

    int size = 0;
    curr = head;
    while (curr->next != head && curr->next != NULL)
    {
        size++;
        curr = curr->next;
    }

    if (curr->next != NULL)
        size++;
    return size;
}

int rotate(t_stack **head)
{
    if ((*head)->next != NULL)
        *head = (*head)->prev;
    return 0;
}

int reverse_rotate(t_stack **head)
{
    if ((*head)->next != NULL)
        *head = (*head)->next;
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
        if (curr_a->next != NULL)
            curr_a = curr_a->next;
        if (curr_b->next != NULL)
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
    head_a = malloc(sizeof(t_stack));
    head_b = malloc(sizeof(t_stack));
    initialize(head_a, head_b);
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
        push(head_a, atoi(args[i]));

    visualize(head_a, head_b);
}