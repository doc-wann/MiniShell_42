/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 02:52:51 by nsutter           #+#    #+#             */
/*   Updated: 2023/06/23 14:50:12 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*x1;
	unsigned char	*x2;
	int				y;

	x1 = (unsigned char *)s1;
	x2 = (unsigned char *)s2;
	y = 0;
	while (x1[y] != '\0' && x2[y] != '\0' && x1[y] == x2[y])
		y++;
	return (x1[y] - x2[y]);
}
