NAME				=	minishell

# PATHS #
LIBFT_PATH			=	./libft/
INCS_PATH			=	./includes/
SRCS_PATH 			=	./sources/
SRCS_PATH_ENV	 	=	./sources/environment/
SRCS_PATH_BUILTIN 	=	./sources/builtin/
SRCS_PATH_SIGNAL 	=	./sources/signal/
SRCS_PATH_CMD	 	=	./sources/cmd/
SRCS_PATH_LEXER	 	=	./sources/lexer/
SRCS_PATH_EXEC	 	=	./sources/execution/
SRCS_PATH_ERROR	 	=	./sources/error/
SRCS_PATH_REDIR 	=	./sources/redirection/
OBJS_PATH 			=	./objects/

# FILES #
LIBFT				=	./libft/libft.a

# HEADERS #
HEADER				=	${INCS_PATH}/minishell.h

# SOURCES #
SRCS				=	${SRCS_PATH}/main.c			\
						${SRCS_PATH}/init.c			\
						${SRCS_PATH}/exit.c

SRCS_ENV			=	${SRCS_PATH_ENV}/env_init.c

SRCS_BUILTIN		=	${SRCS_PATH_BUILTIN}/builtin.c					\
						${SRCS_PATH_BUILTIN}/builtin/builtin_cd.c		\
						${SRCS_PATH_BUILTIN}/builtin/builtin_echo.c		\
						${SRCS_PATH_BUILTIN}/builtin/builtin_env.c		\
						${SRCS_PATH_BUILTIN}/builtin/builtin_exit.c		\
						${SRCS_PATH_BUILTIN}/builtin/builtin_export.c	\
						${SRCS_PATH_BUILTIN}/builtin/builtin_pwd.c		\
						${SRCS_PATH_BUILTIN}/builtin/builtin_unset.c

SRCS_SIGNAL			=	${SRCS_PATH_SIGNAL}/signal.c					\
						${SRCS_PATH_SIGNAL}/signal_int.c				\
						${SRCS_PATH_SIGNAL}/signal_no_int.c

SRCS_CMD			=	${SRCS_PATH_CMD}/cmd_list.c

SRCS_LEXER			=	${SRCS_PATH_LEXER}/lexer.c

SRCS_EXEC			=	${SRCS_PATH_EXEC}/exec_cmd.c					\
						${SRCS_PATH_EXEC}/exec_builtin.c				\
						${SRCS_PATH_EXEC}/exec_path.c

SRCS_ERROR			=	${SRCS_PATH_ERROR}/error.c						\
						${SRCS_PATH_ERROR}/error_builtin_cd.c			\
						${SRCS_PATH_ERROR}/error_exec_cmd.c

SRCS_REDIR			=	${SRCS_PATH_REDIR}/redir.c

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

VPATH 		=	${SRCS_PATH} ${SRCS_PATH_ENV} ${SRCS_PATH_BUILTIN} ${SRCS_PATH_SIGNAL} ${SRCS_PATH_CMD} ${SRCS_PATH_LEXER} ${SRCS_PATH_EXEC} ${SRCS_PATH_ERROR} ${SRCS_PATH_REDIR}

${OBJS_PATH}%.o: %.c
				@mkdir -p ${OBJS_PATH}
				@${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@

OBJS				=	${addprefix ${OBJS_PATH}, ${notdir ${SRCS:.c=.o}}}
OBJS_ENV			=	${addprefix ${OBJS_PATH}, ${notdir ${SRCS_ENV:.c=.o}}}
OBJS_BUILTIN		=	${addprefix ${OBJS_PATH}, ${notdir ${SRCS_BUILTIN:.c=.o}}}
OBJS_SIGNAL			=	${addprefix ${OBJS_PATH}, ${notdir ${SRCS_SIGNAL:.c=.o}}}
OBJS_CMD			=	${addprefix ${OBJS_PATH}, ${notdir ${SRCS_CMD:.c=.o}}}
OBJS_LEXER			=	${addprefix ${OBJS_PATH}, ${notdir ${SRCS_LEXER:.c=.o}}}
OBJS_EXEC			=	${addprefix ${OBJS_PATH}, ${notdir ${SRCS_EXEC:.c=.o}}}
OBJS_ERROR			=	${addprefix ${OBJS_PATH}, ${notdir ${SRCS_ERROR:.c=.o}}}
OBJS_REDIR			=	${addprefix ${OBJS_PATH}, ${notdir ${SRCS_REDIR:.c=.o}}}

${NAME}:		${OBJS} ${OBJS_ENV} ${OBJS_BUILTIN} ${OBJS_SIGNAL} ${OBJS_CMD} ${OBJS_LEXER} ${OBJS_EXEC} ${OBJS_ERROR} ${OBJS_REDIR}
				@echo ${BLUE} "${NAME} is compiling..." ${EOC}
				@make -s -C ${LIBFT_PATH}
				@${CC} ${CFLAGS} ${OBJS} ${OBJS_ENV} ${OBJS_BUILTIN} ${OBJS_SIGNAL} ${OBJS_CMD} ${OBJS_LEXER} ${OBJS_EXEC} ${OBJS_ERROR} ${OBJS_REDIR} ${LIBFT} ${IFLAGS} -lreadline -o ${NAME}
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
