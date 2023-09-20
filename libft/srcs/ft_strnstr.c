/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:29:37 by nsutter           #+#    #+#             */
/*   Updated: 2022/06/22 21:21:21 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	x;
	size_t	y;

	if (little[0] == '\0')
		return ((char *)big);
	x = 0;
	while (big[x] != '\0' && x < len)
	{
		y = 0;
		while (big[x + y] != '\0' && big[x + y] == little[y] && (x + y) < len)
		{
			if (little[y + 1] == '\0')
				return ((char *)big + x);
			y++;
		}
		x++;
	}
	return (NULL);
}
