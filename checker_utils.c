#include "./includes/push_swap.h"

int	check_duplicated_elements(char **args, int number_of_args)
{
	int	i;
	int	j;

	i = -1;
	while (++i < number_of_args)
	{
		j = i;
		while (++j < number_of_args)
			if (!ft_strcmp(args[j], args[i]))
			{
				write(1, RED, ft_strlen(RED));
				write(1, "DUPLICATED ELEMENT: \"", 21);
				write(1, args[i], ft_strlen(args[i]));
				write(1, "\"!\n", 3);
				exit(EXIT_FAILURE);
			}
	}
	return (1);
}
