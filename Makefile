NAME				=	minishell

# PATHS #
LIBFT_PATH			=	./libft/
INCS_PATH			=	./includes/
SRCS_PATH 			=	./sources/
SRCS_PATH_BUILTIN 	=	./sources/builtin/
SRCS_PATH_SIGNAL 	=	./sources/signal/
OBJS_PATH 			=	./objects/

# FILES #
LIBFT				=	./libft/libft.a

# HEADERS #
HEADER				=	${INCS_PATH}/minishell.h

# SOURCES #
SRCS				=	${SRCS_PATH}/main.c			\
						${SRCS_PATH}/init.c			\
						${SRCS_PATH}/loop.c			\
						${SRCS_PATH}/cmd.c			\
						${SRCS_PATH}/cmd_list.c		\
						${SRCS_PATH}/exit.c			\
						${SRCS_PATH}/error.c

SRCS_BUILTIN		=	${SRCS_PATH_BUILTIN}/builtin.c					\
						${SRCS_PATH_BUILTIN}/builtin/builtin_cd.c		\
						${SRCS_PATH_BUILTIN}/builtin/builtin_echo.c		\
						${SRCS_PATH_BUILTIN}/builtin/builtin_env.c		\
						${SRCS_PATH_BUILTIN}/builtin/builtin_exit.c		\
						${SRCS_PATH_BUILTIN}/builtin/builtin_export.c	\
						${SRCS_PATH_BUILTIN}/builtin/builtin_pwd.c		\
						${SRCS_PATH_BUILTIN}/builtin/builtin_unset.c

SRCS_SIGNAL			=	${SRCS_PATH_SIGNAL}/signal_int.c				\
						${SRCS_PATH_SIGNAL}/signal_no_int.c

# COMPILATION #
CC			=	cc
RM			=	rm -rf
AR			=	ar -rcs
CFLAGS		=	-Wall -Werror -Wextra
IFLAGS		=	-I ./includes

# COLORS #
BLACK		=	"\033[1;30m"
RED			=	"\033[1;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[1;34m"
PURPLE		=	"\033[1;35m"
CYAN		=	"\033[1;36m"
WHITE		=	"\033[1;37m"
EOC			=	"\033[0;0m"

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

VPATH 		=	${SRCS_PATH} ${SRCS_PATH_BUILTIN} ${SRCS_PATH_SIGNAL}

${OBJS_PATH}%.o: %.c
				@mkdir -p ${OBJS_PATH}
				@${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@

OBJS				=	${addprefix ${OBJS_PATH}, ${notdir ${SRCS:.c=.o}}}
OBJS_BUILTIN		=	${addprefix ${OBJS_PATH}, ${notdir ${SRCS_BUILTIN:.c=.o}}}
OBJS_SIGNAL			=	${addprefix ${OBJS_PATH}, ${notdir ${SRCS_SIGNAL:.c=.o}}}

${NAME}:		${OBJS} ${OBJS_BUILTIN} ${OBJS_SIGNAL}
				@echo ${BLUE} "${NAME} is compiling..." ${EOC}
				@make -s -C ${LIBFT_PATH}
				@${CC} ${CFLAGS} ${OBJS} ${OBJS_BUILTIN} ${OBJS_SIGNAL} ${LIBFT} ${IFLAGS} -lreadline -o ${NAME}
				@echo ${GREEN} "${NAME} is compilated!" ${EOC}

all:			${NAME}

norminette:		
				norminette -R CheckForbiddenSourceHeader *

clean:			
				@${RM} ${OBJS_PATH}
				@make clean -s -C ${LIBFT_PATH}
				@echo ${RED} "Object files ${NAME} are removed!" ${EOC}

fclean:			clean
				@${RM} ${NAME}
				@make fclean -s -C ${LIBFT_PATH}
				@echo ${RED} "${NAME} is removed!" ${EOC}

re:				fclean all

.PHONY:			all bonus norminette clean fclean re 
