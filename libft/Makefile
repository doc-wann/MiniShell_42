# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 19:27:39 by nsutter           #+#    #+#              #
#    Updated: 2023/06/23 14:52:06 by nsutter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

# FILES #
SRCS_PATH 	= ./srcs/
OBJS_PATH 	= ./objs/

# COMPILATION #
CC 			= gcc
RM 			= rm -rf
CFLAGS 		= -Wall -Wextra -Werror
AR			= ar -rcs

# SOURCE FILES #
SRCS 		= 	ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_strlen.c			\
				ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memmove.c		\
				ft_strlcpy.c		\
				ft_strlcat.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strncmp.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strnstr.c		\
				ft_atoi.c			\
				ft_calloc.c			\
				ft_strdup.c			\
				ft_substr.c			\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_split.c			\
				ft_itoa.c			\
				ft_strmapi.c		\
				ft_striteri.c		\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_putstr.c			\
				ft_putchar.c		\
				ft_strcmp.c			\
				ft_get_next_line.c	\
				ft_printf_chr.c		\
				ft_printf_hex.c		\
				ft_printf_nbr.c		\
				ft_printf_ptr.c		\
				ft_printf_str.c		\
				ft_printf_uns.c		\
				ft_printf.c

# COLORS #
BLACK	=	"\033[1;30m"
RED		=	"\033[1;31m"
GREEN	=	"\033[1;32m"
YELLOW	=	"\033[1;33m"
BLUE	=	"\033[1;34m"
PURPLE	=	"\033[1;35m"
CYAN	=	"\033[1;36m"
WHITE	=	"\033[1;37m"
EOC		=	"\033[0;0m"

VPATH 		= ${SRCS_PATH}

OBJS 		= ${addprefix ${OBJS_PATH}, ${notdir ${SRCS:.c=.o}}}

${OBJS_PATH}%.o: %.c
			@mkdir -p ${OBJS_PATH}
			@${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			@echo ${BLUE} "${NAME} is compiling..." ${EOC}
			@${AR} ${NAME} ${OBJS}
			@echo ${GREEN} "${NAME} is compilated!" ${EOC}

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: 		$(NAME)

clean:
			@${RM} ${OBJS}
			@${RM} ${OBJS_PATH}
			@echo ${RED} "Object files ${NAME} are removed!" ${EOC}

fclean:
			@${RM} ${OBJS}
			@${RM} ${OBJS_PATH}
			@${RM} ${NAME}
			@echo ${RED} "${NAME} is removed!" ${EOC}

re:			fclean all

.PHONY:		all clean fclean re