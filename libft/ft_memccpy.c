#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (i < n)
	{
		(d[i] = s[i]);
		if (s[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
