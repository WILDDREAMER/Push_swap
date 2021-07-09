/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:49:48 by ozakkare          #+#    #+#             */
/*   Updated: 2021/07/09 12:17:55 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill(char *holder, char **line)
{
	char	*str;

	str = NULL;
	if (holder)
	{
		str = ft_strchr(holder, '\n');
		if (str)
		{
			*str = '\0';
			*line = ft_strdup(holder);
			ft_strcpy(holder, ++str);
		}
		else
		{
			*line = ft_strdup(holder);
			holder = NULL;
		}
	}
	else
		*line = ft_calloc(1, 1);
	return (str);
}

void	swap_(char *buff, char **line)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(tmp, buff);
	free(tmp);
}

void	free_buff(char **buff, char **holder)
{
	free(*buff);
	free(holder);
	*holder = 0;
}

int	ifempty(char **holder, char *buff, int fd, char **line)
{
	int		size_read;
	char	*str;

	str = fill(*holder, line);
	while (!str)
	{
		size_read = read(fd, buff, BUFFER_SIZE);
		if (size_read == 0)
		{
			free_buff(&buff, holder);
			return (0);
		}
		*(buff + size_read) = '\0';
		str = ft_strchr(buff, '\n');
		if (str)
		{
			*str++ = '\0';
			free(*holder);
			*holder = ft_strdup(str);
		}
		swap_(buff, line);
	}
	free(buff);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*holder;
	char		*buff;

	if ((read(fd, NULL, 0) != 0) || fd < 0)
		return (-1);
	if (BUFFER_SIZE >= 2147483647)
		return (-1);
	buff = malloc(BUFFER_SIZE + 1);
	return (ifempty(&holder, buff, fd, line));
}
