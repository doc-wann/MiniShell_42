/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:54:05 by nsutter           #+#    #+#             */
/*   Updated: 2022/06/22 21:22:02 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
	{
		dst[len] = (*f)(len, s[len]);
		len++;
	}
	dst[len] = '\0';
	return (dst);
}
