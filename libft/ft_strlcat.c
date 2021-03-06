#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_src;

	s_src = ft_strlen(src);
	if (!dst && size == 0)
		return (s_src);
	if (ft_strlen(dst) > size)
		s_src = s_src + size;
	else
		s_src = s_src + ft_strlen(dst);
	while (*dst && size != 0)
	{
		dst++;
		size--;
	}
	while (*src && 1 < size)
	{
		*dst++ = *src++;
		size--;
	}
	if (size != 0)
		*dst = '\0';
	return (s_src);
}
