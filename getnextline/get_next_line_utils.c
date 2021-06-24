/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:43:41 by ozakkare          #+#    #+#             */
/*   Updated: 2019/11/04 11:03:18 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		len;
	int		i;

	len = 0;
	while (s1[len])
		len++;
	len++;
	s = malloc(len * sizeof(char));
	if (s == 0)
		return (0);
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	s[i] = '\0';
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*c;
	int				i;

	i = 0;
	if (!(c = malloc(count * size)))
		return (0);
	while (c[i])
	{
		c[i] = '\0';
		i++;
	}
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	char	*p;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	lens1 = 0;
	lens2 = 0;
	while (s1[lens1])
		lens1++;
	while (s2[lens2])
		lens2++;
	if (!(p = malloc((lens1 + lens2 + 1) * sizeof(char))))
		return (0);
	i = -1;
	while (++i < lens1)
		p[i] = s1[i];
	j = 0;
	while (i < (lens1 + lens2))
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char*)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char*)s);
	return (0);
}

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
