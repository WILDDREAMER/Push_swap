#include "libft.h"

int	whitespace(char c)
{
	if (c == '\n' || c == '\v' || c == '\f' || c == '\t' || c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				negativity;
	unsigned long	result;

	result = 0;
	negativity = 1;
	i = 0;
	while (whitespace(str[i]))
		i++;
	if (str[i] == '-')
		negativity = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (result > 2147483647 && negativity == 1)
		return (-1);
	if (result > 2147483648 && negativity == -1)
		return (0);
	return (result * negativity);
}
