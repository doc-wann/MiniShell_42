/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:27:08 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/19 17:25:41 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strncpy(char *src, unsigned int n);
int		ft_arrlen(char **s);

/********************/
/*	get_next_line	*/
/********************/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

/********************/
/*	  ft_printf  	*/
/********************/

# if defined (__linux__)
#  define PTR_NULL "(nil)"
# elif defined (__APPLE__)
#  define PTR_NULL "0x0"
# endif

int		ft_printf(const char *format, ...);
int		ft_check_fmt(va_list args, const char format);

/* c : character */
int		ft_tot_chr(char chr);

/* s : string of characters */
int		ft_tot_str(char *str);
int		ft_put_str(char *str);

/* p : pointer adress */
int		ft_tot_ptr(unsigned long int ptr);
void	ft_put_ptr(unsigned long int ptr);
int		ft_len_ptr(unsigned long int ptr);

/* d : signed decimal integer */
/* i : signed decimal integer */
int		ft_tot_nbr(int nbr);

/* u : unsigned decimal integer */
int		ft_tot_uns(unsigned int nbr);
char	*ft_itoa_uns(unsigned int nbr);
int		ft_len_uns(unsigned int nbr);

/* x : unsigned hexadecimal integer */
/* X : unsigned hexadecimal integer (capital letters) */
int		ft_tot_hex(unsigned int nbr, const char format);
void	ft_put_hex(unsigned int nbr, const char format);
int		ft_len_hex(unsigned int nbr);

/* helper functions */
void	ft_putchar(char c);

#endif