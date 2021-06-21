#include "libft.h"

static int	ft_wherestart(char const *s1, char const *set)
{
	int	start;
	int	i;

	start = 0;
	while (s1[start] != '\0')
	{
		i = 0;
		while (s1[start] != set[i] && set[i] != '\0')
			i++;
		if (s1[start] == set[i])
			start++;
		else
			break ;
	}
	return (start);
}

static int	ft_whereend(char const *s1, char const *set, int start)
{
	int	end;
	int	i;

	end = ft_strlen(s1);
	i = 0;
	while (end >= start)
	{
		i = 0;
		while (s1[end] != set[i] && set[i] != '\0')
			i++;
		if (s1[end] == set[i])
			end--;
		else
			break ;
	}
	return (end);
}

static	char	*ft_case(char const *s1)
{
	int		i;
	char	*fin;

	i = 0;
	fin = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!fin)
		return (0);
	while (i < (int)ft_strlen(s1))
	{
		fin[i] = s1[i];
		i++;
	}
	fin[i] = '\0';
	return (fin);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*fin;
	int		start;
	int		end;
	int		i;
	int		s;

	if (s1 == NULL)
		return (0);
	if (s1 && !set)
		return (ft_case(s1));
	start = ft_wherestart(s1, set);
	end = ft_whereend(s1, set, start);
	i = 0;
	s = end - start + 1;
	fin = (char *)malloc((s + 1) * sizeof(char));
	if (!fin)
		return (0);
	while (i < s)
	{
		fin[i] = s1[start];
		i++;
		start++;
	}
	fin[i] = '\0';
	return (fin);
}
