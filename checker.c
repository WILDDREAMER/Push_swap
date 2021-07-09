#include "./includes/push_swap.h"

void	print_error(void)
{
	write(1, "\e[1;31mKO\n", ft_strlen("\e[1;31mKO\n"));
	exit(EXIT_FAILURE);
}

void	checker_main(t_main *vars, t_stack **a, t_stack **b)
{
	char	*print;

	check_duplicated_elements(vars->args, vars->number_of_args);
	while (--vars->i >= 0)
		push(a, ft_atoi(vars->args[vars->i]));
	while (get_next_line(0, &vars->line) > 0)
	{
		handle_input(a, b, vars->line);
		free(vars->line);
		vars->line = NULL;
	}
	if (stack_size(*a) != vars->number_of_args)
		print_error();
	print = checker(*a);
	write(1, print, ft_strlen(print));
	free_t_stack(*a);
	free_t_stack(*b);
}

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_main	vars;
	int		arg_len;

	if (argc < 2)
		return (0);
	vars.number_of_args = 0;
	head_a = NULL;
	head_b = NULL;
	vars.args = NULL;
	check_args(argc, &vars, argv);
	vars.i = vars.number_of_args;
	if (vars.number_of_args == 0)
		return (0);
	checker_main(&vars, &head_a, &head_b);
	if (argc == 2)
		free_double_pointer(vars.args);
	return (1);
}
