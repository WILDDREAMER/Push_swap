#include "libft.h"

static int	ft_intlen(int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	if (n <= 0)
	{
		nb = n * -1;
		i++;
	}
	else
		nb = n;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	unsigned int	i;

	i = ft_intlen(n);
	if (n < 0)
		nb = -n;
	else
		nb = n;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
