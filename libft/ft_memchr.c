#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)s;
	while (i < n)
	{
		if (a[i] == c)
			return (a + i);
		i++;
	}
	return (0);
}
