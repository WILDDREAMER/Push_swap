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

int main(int argc, char **argv)
{
    t_stack *head;
    t_stack	*curr;
    int i;

    head = malloc(sizeof(t_stack));
    head->val = atoi(argv[1]);
    head->prev = head;
    head->next = head;

    i = 1;
    while (++i < argc)
        push(head,atoi(argv[i]));

	pop(&head, 3);
    curr = head;

    while(curr->next != head){
        printf("%d ~ ", curr->val);
        curr = curr->next;
    }
    printf("%d", curr->val);
}