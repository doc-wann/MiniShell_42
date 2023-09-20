/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:49:58 by nsutter           #+#    #+#             */
/*   Updated: 2022/06/06 16:22:37 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		x;
	int		y;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	x = 0;
	while (s1[x] != '\0')
	{
		dst[x] = s1[x];
		x++;
	}
	y = 0;
	while (s2[y] != '\0')
	{
		dst[x + y] = s2[y];
		y++;
	}
	dst[x + y] = '\0';
	return (dst);
}
