#include "push_swap.h"

void push(t_stack *head, int val)
{
    t_stack *new;
    t_stack *top;

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
        (*head)->next = NULL;
        (*head)->prev = NULL;
        return (0);

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

    if (head->next != head)
    {
        top = head->prev;
        tmp = top->val;
        top->val = top->prev->val;
        top->prev->val = tmp;
    }
}

void push_top( t_stack *to, t_stack *from)
{
    int top;

    if (from->next != NULL)
    {
        top = from->prev->val;
        push(from, top);
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

int stack_size(t_stack *head){
    t_stack *curr;

    int size = 0;
    curr = head;
    while(curr->next != head && curr->next != NULL)
    {
        size++;
        curr = curr->next;
    }

    if (curr->next != NULL)
        size++;
    return size;
}

void visualize(t_stack *a, t_stack *b){

    // t_stack *curr_a;
    // t_stack *curr_b;
    // char val_a;
    // char val_b;

    // int size_a = stack_size(a);
    // int size_b = stack_size(b);
    // int size = (size_a > size_b) ? size_a : size_b;

    // curr_a = a;
    // curr_b = b;

    // for (int i = 0; i < size; i++)
    // {
    //     if (curr_a)
    // }
    

    t_stack *curr_a;
    t_stack *curr_b;
    int val_a;
    int val_b;

    curr_a = a;
    while (curr_a->next != a && curr_a->next != NULL)
    {
        printf("||  %d  ||\n", curr_a->val);
        curr_a = curr_a->next;
    }
    if (curr_a->next != NULL)
        printf("||  %d  ||\n----------------------\n", curr_a->val);    
}
int main(int argc, char **argv)
{
    t_stack *head_a;
    t_stack *head_b;

    int i;

    head_a = malloc(sizeof(t_stack));
    head_b = malloc(sizeof(t_stack));
    initialize(head_a, head_b);

    i = 0;

    if (argc < 2)
        return 0;
    while (++i < argc)
        push(head_a, atoi(argv[i]));
    printf("%d", stack_size(head_b));
    visualize(head_a, head_b);
    push_top(head_a, head_b);
}