/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:50:47 by nsutter           #+#    #+#             */
/*   Updated: 2022/06/19 22:38:12 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_nb_trim(char const *set, char c)
{
	unsigned int	x;

	x = 0;
	while (set[x] != '\0')
	{
		if (set[x] == c)
			return (1);
		x++;
	}
	return (0);
}

static char	*ft_str_trim(char *str, char const *s1, size_t beg, size_t end)
{
	size_t	x;

	x = 0;
	while (beg < end)
	{
		str[x] = s1[beg];
		x++;
		beg++;
	}
	str[x] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	size_t			beg;
	size_t			end;
	unsigned int	max;

	if (s1 == 0 || set == 0)
		return (NULL);
	beg = 0;
	end = ft_strlen(s1);
	while (s1[beg] != '\0' && ft_nb_trim(set, s1[beg]))
		beg++;
	while (s1[end - 1] != '\0' && ft_nb_trim(set, s1[end - 1]))
		end--;
	if (beg > end)
		max = 1;
	else
		max = end - beg + 1;
	str = (char *)malloc(sizeof(char) * max);
	if (str == NULL)
		return (NULL);
	ft_str_trim(str, s1, beg, end);
	return (str);
}
