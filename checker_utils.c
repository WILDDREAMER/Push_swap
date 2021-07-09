#include "./includes/push_swap.h"

void	check_number(char **args, int i)
{
	int	k;
	int	arg_len;

	if (ft_atoi(args[i]) == -1
		&& (ft_strncmp(args[i], "-1", 3) || ft_strncmp(args[i], "-1", 3)))
	{
		write(1, RED, ft_strlen(RED));
		write(1, "MAX INT EXCEEDED !\n", 19);
		exit(EXIT_FAILURE);
	}
	arg_len = ft_strlen(args[i]);
	k = -1;
	while (++k < arg_len)
	{
		if (!ft_isdigit(args[i][k]) && !(!k && args[i][k] == '-'))
		{
			write(1, RED, ft_strlen(RED));
			write(1, "SYNTAX ERROR !\n", 15);
			exit(EXIT_FAILURE);
		}
	}
}

int	check_duplicated_elements(char **args, int number_of_args)
{
	int	i;
	int	j;
	int	ret;

	i = -1;
	while (++i < number_of_args)
	{
		j = i;
		check_number(args, i);
		while (++j < number_of_args)
		{
			if (!ft_strcmp(args[j], args[i]))
			{
				write(1, RED, ft_strlen(RED));
				write(1, "DUPLICATED ELEMENT: \"", 21);
				write(1, args[i], ft_strlen(args[i]));
				write(1, "\"!\n", 3);
				exit(EXIT_FAILURE);
			}
		}
	}
	return (1);
}
