#include "./includes/push_swap.h"

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