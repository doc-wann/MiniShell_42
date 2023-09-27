#include "../libft.h"

char    *ft_strncpy(char *src, unsigned int n)
{
    unsigned int    index;
	char	*dest;

    dest = ft_calloc(n, sizeof(char));

    index = 0;

    while (index < n && src[index] != '\0')
    {
        dest[index] = src[index];
        index++;
    }
    while (index < n)
    {
        dest[index] = '\0';
        index++;
    }
    return (dest);
}