#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (s == 0)
		return (0);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	if (start > ft_strlen(s))
		return (new = ft_strdup(""));
	i = 0;
	while (i < len)
	{
		new[i] = s[start];
		start++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
