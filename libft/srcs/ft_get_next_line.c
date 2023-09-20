/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:08:59 by nsutter           #+#    #+#             */
/*   Updated: 2022/07/07 16:10:18 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_read_line(int fd, char *text)
{
	char		*buff;
	char		*temp;
	int			nb_read;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	nb_read = 1;
	while (nb_read != 0)
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if (nb_read <= 0)
			break ;
		buff[nb_read] = '\0';
		if (text == NULL)
			text = ft_strdup("\0");
		temp = text;
		text = ft_strjoin(temp, buff);
		free(temp);
		if (ft_strchr(text, '\n'))
			break ;
	}
	free(buff);
	return (text);
}

static char	*ft_curr_line(char *text)
{
	char	*dst;
	int		size;
	int		x;

	if (text == NULL)
		return (NULL);
	x = 0;
	while (text[x] != '\0')
	{
		x++;
		if (text[x - 1] == '\n')
			break ;
	}
	size = x++;
	dst = malloc(sizeof(char) * (size + 1));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, text, size);
	dst[size] = '\0';
	return (dst);
}

static char	*ft_next_line(char *text)
{
	char	*dst;
	int		size;
	int		x;

	if (text == NULL)
		return (NULL);
	x = 0;
	while (text[x] != '\0' && text[x] != '\n')
		x++;
	if (text[x] == '\0' || text[x + 1] == '\0')
		return (NULL);
	if (text[x] != '\0')
		x++;
	size = ft_strlen(text + x) + 1;
	dst = malloc(sizeof(char) * (size + 1));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, text + x, size);
	dst[size] = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	static char	*text[1024];

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	text[fd] = ft_read_line(fd, text[fd]);
	line = ft_curr_line(text[fd]);
	temp = text[fd];
	text[fd] = ft_next_line(temp);
	free(temp);
	return (line);
}
