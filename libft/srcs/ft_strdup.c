/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:23:59 by nsutter           #+#    #+#             */
/*   Updated: 2022/06/22 21:21:36 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		len;

	len = 0;
	while (s[len] != '\0')
		len++;
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
	{
		dst[len] = s[len];
		len++;
	}
	dst[len] = '\0';
	return (dst);
}
