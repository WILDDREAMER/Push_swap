#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	while (s[len] != c)
	{
		if (len == 0)
			return (NULL);
		len--;
	}
	return ((char *)s + len);
}
