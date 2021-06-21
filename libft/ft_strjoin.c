#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (0);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (0);
	j = ft_strlen(s1);
	ft_strcpy(new, s1);
	ft_strcpy(new + j, s2);
	return (new);
}
