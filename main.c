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

int pop(t_stack *head, int val){
	t_stack *curr;

	curr = head;
	if (head->val == val)
	//cannot head's value
		return (0);

	//loop over the it until we find our value
    while(curr->val != val && curr->next != head)
        curr = curr->next;

	if (curr->val == val){
		curr->prev->next = curr->next; 
		curr->next->prev = curr->prev; 
		return (val);
	}
	return (0);
}

int main(void)
{
    t_stack *head;
    t_stack	*curr;

    head = malloc(sizeof(t_stack));
    head->val = 0;
    head->prev = head;
    head->next = head;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
	pop(head, 2);
    curr = head;
    while(curr->next != head){
        printf("%d ~ ", curr->val);
        curr = curr->next;
    }
    printf("%d", curr->val);
}