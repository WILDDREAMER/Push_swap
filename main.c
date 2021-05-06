#include "push_swap.h"

void push(t_stack *head, int val)
{
    t_stack *new;
    t_stack *top;

    new = malloc(sizeof(t_stack));
	top = head->prev;
	top->next = new;
	head->prev = new;
	new->prev = top;
	new->next = head;
	new->val = val;
}

int pop(t_stack **head, int val){
	t_stack *curr;

	curr = *head;
	if ((*head)->next == *head)
	//cannot delete head
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
    while(curr->val != val && curr->next != *head)
        curr = curr->next;

	if (curr->val == val){
		curr->prev->next = curr->next; 
		curr->next->prev = curr->prev; 
		return (val);
	}
	return (0);
}

void swap(t_stack *head){
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

void ss(t_stack *head_a, t_stack *head_b){
    swap(head_a);
    swap(head_b);
}

int main(int argc, char **argv)
{
    t_stack *head_a;
    t_stack *head_b;
    t_stack	*curr;
    int i;

    head_a = malloc(sizeof(t_stack));
    head_b = malloc(sizeof(t_stack));
    head_a->val = atoi(argv[1]);
    head_a->prev = head_a;
    head_a->next = head_a;

    i = 1;
    while (++i < argc)
        push(head_a,atoi(argv[i]));

	swap(head_a);
    curr = head_a;

    while(curr->next != head_a){
        printf("%d ~ ", curr->val);
        curr = curr->next;
    }
    printf("%d", curr->val);
}