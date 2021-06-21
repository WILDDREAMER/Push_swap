#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dst;
	char		*ssrc;

	dst = (char *)dest;
	ssrc = (char *)src;
	if (dest == NULL && src == NULL)
		return (0);
	if (dst > ssrc)
	{
		dst = (char *)dest + (n - 1);
		ssrc = (char *)src + (n - 1);
		while (n > 0)
		{
			*(dst--) = *(ssrc--);
			n--;
		}
	}
	else
		ft_memcpy(dst, ssrc, n);
	return (dest);
}
