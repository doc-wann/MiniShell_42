/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:29:48 by nsutter           #+#    #+#             */
/*   Updated: 2022/06/22 21:19:49 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		x;
	char	chr;

	x = 0;
	chr = c;
	while (s[x] != '\0')
	{
		if (s[x] == chr)
			return ((char *)(s + x));
		x++;
	}
	if (s[x] == chr)
		return ((char *)(s + x));
	return (NULL);
}
