#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define WHT "\e[0;37m"
# define BLK "\e[1;30m"
# define RED "\e[1;31m"
# define GRN "\e[1;32m"
# define YEL "\e[1;33m"
# define BLU "\e[1;34m"
# define MAG "\e[1;35m"
# define CYN "\e[1;36m"

# define BUFFER_SIZE 100

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../getnextline/get_next_line.h"

typedef struct s_stack
{
	int				val;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;
typedef struct s_instructions
{
	char					*val;
	struct s_instructions	*next;
}				t_instructions;

typedef struct s_five
{
	int		min_index;
	int		min_val;
	int		stop_checking_for_second;
	int		i;
	int		j;
	int		sec_min;
}				t_five;

typedef struct s_big_numbers
{
	int		*n_moves;
	int		size;
	int		size_a;
	int		first_size;
	int		i;
	int		j;
	int		k;
	int		index_curr_move;
	t_stack	*cur;
	int		closest;
	int		min_index;
	int		min_val;
}				t_big_numbers;

typedef struct s_main
{
	char	**args;
	char	*line;
	int		number_of_args;
	int		i;
	int		argc;
}				t_main;

int		stack_size(t_stack *head);
int		add_back(t_stack **head, int val);
int		push(t_stack **head, int val);
int		pop(t_stack **head);
int		pop_last(t_stack **head);
void	push_top(t_stack **to, t_stack **from);
void	swap(t_stack *head);
void	ss(t_stack *head_a, t_stack *head_b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
int		rotate(t_stack **head);
int		reverse_rotate(t_stack **head);
void	rrr(t_stack **a, t_stack **b);
void	rr(t_stack **head_a, t_stack **head_b);
void	visualize(t_stack *a, t_stack *b);
int		args_length(char **args);
void	visualize(t_stack *a, t_stack *b);
int		check_duplicated_elements(char **args, int number_of_args);
int		handle_input(t_stack **a, t_stack **b, char *line);
int		get_index_of_max(t_stack *head);
int		get_index_of_min(t_stack *head);
int		get_index_of_node(t_stack *head, int		val);
int		get_val_of_min(t_stack *head);
int		get_val_of_second(t_stack *head);
int		get_val_of_max(t_stack *head);
int		get_val_of_second_max(t_stack *head);
int		get_val_of_mid(t_stack *head);
int		sort_five(t_stack	**a, t_stack **b, t_instructions **instrcs);
int		sort_three(t_stack	*head, t_instructions **instrcs);
int		check_second_last(t_stack **a, t_stack **b, int		*stop);
int		add_node(char *val, t_instructions **instrcs);
int		unsort_two(t_stack	*head, t_instructions **instcs);
void	sort_big_numbers(t_stack **a, t_stack **b, t_instructions **instrcs);
void	free_t_stack(t_stack *stack);
void	free_double_pointer(char **tab);
void	free_t_instrcs(t_instructions *stack);
int		delete_node(t_stack **head, int val);
t_stack	*create_cpy(t_stack *head);
void	calculate_instrcs(t_big_numbers *vars, t_stack **a, t_stack **b);
int		index_of_curr_move(int		*tab, int size);
void	isolate_min_max(t_stack **a, t_stack **b, t_instructions **instrcs);
void	not_min_max(t_stack **a, t_stack **b,
			t_instructions **instrcs, int	mid);
int		get_index_of_closest(t_stack *head, int val);
int		optimize_instrucs(t_instructions **head);
char	*checker(t_stack *a);
int		handle_input(t_stack **a, t_stack **b, char *line);
void	check_args(int argc, t_main *vars, char **argv);
int		sort_two(t_stack	*head, t_instructions **instrcs);
#endif
