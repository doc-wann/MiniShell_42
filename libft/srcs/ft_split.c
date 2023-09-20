/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:51:51 by nsutter           #+#    #+#             */
/*   Updated: 2022/06/22 21:21:50 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_nb_split(char const *s, char c)
{
	unsigned int	x;
	int				n;

	x = 0;
	n = 0;
	while (s[x] != '\0')
	{
		while (s[x] == c)
			x++;
		if (s[x] != '\0')
			n++;
		while (s[x] != c && s[x] != '\0')
			x++;
	}
	return (n);
}

static char	*ft_str_split(char const *s, int x, int size)
{
	char	*str;
	int		z;

	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	z = 0;
	while (z < size)
	{
		str[z] = s[x];
		z++;
		x++;
	}
	str[z] = '\0';
	return (str);
}

static char	**ft_dst_split(char **dst, char const *s, char c)
{
	int		x;
	int		y;
	int		size;

	x = 0;
	y = 0;
	while (s[x] != '\0')
	{
		while (s[x] == c)
			x++;
		if (s[x] != '\0')
		{
			size = 0;
			while (s[x + size] != c && s[x + size] != '\0')
				size++;
			dst[y] = ft_str_split(s, x, size);
			x = x + size;
			y++;
		}
	}
	dst[y] = NULL;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;

	if (s == 0)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * (ft_nb_split(s, c) + 1));
	if (dst == NULL)
		return (NULL);
	return (ft_dst_split(dst, s, c));
}
