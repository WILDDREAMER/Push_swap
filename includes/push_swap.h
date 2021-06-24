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

typedef struct	s_stack
{
	int val;
	struct s_stack *prev;
	struct s_stack *next;
}				t_stack;

int stack_size(t_stack *head);
int add_back(t_stack **head, int val);
int push(t_stack **head, int val);
int pop(t_stack **head);
int pop_last(t_stack **head);
void push_top(t_stack **to, t_stack **from);
void swap(t_stack *head);
void ss(t_stack *head_a, t_stack *head_b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
int rotate(t_stack **head);
int reverse_rotate(t_stack **head);
void rrr(t_stack **a, t_stack **b);
void rr(t_stack **head_a, t_stack **head_b);
void visualize(t_stack *a, t_stack *b);
int args_length(char **args);
void visualize(t_stack *a, t_stack *b);
char *checker(t_stack *a);
int	check_duplicated_elements(char **args, int number_of_args);
int	handle_input(t_stack **a, t_stack **b, char *line);
int get_index_of_max(t_stack *head);
int get_index_of_min(t_stack *head);
int get_index_of_node(t_stack *head, int val);
int get_val_of_min(t_stack *head);
int get_val_of_second(t_stack *head);

#endif

//ARG="2 5 1 3 4"; ./push_swap $ARG | wc -l; ./push_swap $ARG | ./42_checker/checker_Mac $ARG
//ARG="2 1 5 3 4"; ./push_swap $ARG | wc -l; ./push_swap $ARG | ./42_checker/checker_Mac $ARG
//ARG="5 2 1 3 4"; ./push_swap $ARG | wc -l; ./push_swap $ARG | ./42_checker/checker_Mac $ARG
//ARG="5 1 2 3 4"; ./push_swap $ARG | wc -l; ./push_swap $ARG | ./42_checker/checker_Mac $ARG
//ARG="1 5 2 3 4"; ./push_swap $ARG | wc -l; ./push_swap $ARG | ./42_checker/checker_Mac $ARG
//ARG="1 2 5 3 4"; ./push_swap $ARG | wc -l; ./push_swap $ARG | ./42_checker/checker_Mac $ARG
//ARG="3 5 1 4 2"; ./push_swap $ARG | wc -l; ./push_swap $ARG | ./42_checker/checker_Mac $ARG
//ARG="3 5 1 2 4"; ./push_swap $ARG | wc -l; ./push_swap $ARG | ./42_checker/checker_Mac $ARG
//ARG="3 5 4 1 2"; ./push_swap $ARG | wc -l; ./push_swap $ARG | ./42_checker/checker_Mac $ARG
//ARG="3 5 4 2 1"; ./push_swap $ARG | wc -l; ./push_swap $ARG | ./42_checker/checker_Mac $ARG
//ARG="3 5 2 4 1"; ./push_swap $ARG | wc -l; ./push_swap $ARG | ./42_checker/checker_Mac $ARG
//ARG="3 2 5 4 1"; ./push_swap $ARG | wc -l; ./push_swap $ARG | ./42_checker/checker_Mac $ARG
//ARG="2 3 5 4 1"; ./push_swap $ARG | wc -l; ./push_swap $ARG | ./42_checker/checker_Mac $ARG