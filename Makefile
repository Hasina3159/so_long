NAME			=	so_long

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf


SRCS_PATH		=	./src
LIBFT_PATH		=	./libft
MINILIBX_PATH	=	./minilibx
LIBFT			=	$(LIBFT_PATH)/libft.a
MINILIBX		=	$(MINILIBX_PATH)/libmlx_Linux.a
SRCS 			=	$(shell find . -name "*.c" | grep ./src/ | tr '\n' ' ')

OBJS			=	$(SRCS:.c=.o)

$(SRCS_PATH)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(LIBFT) $(MINILIBX) $(OBJS)
					$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME) $(MINILIBX) -lX11 -lXext -g

$(LIBFT):
					make -C $(LIBFT_PATH) all

$(MINILIBX):
					make -C $(MINILIBX_PATH) all

clean:
					make -C $(LIBFT_PATH) clean
					make -C $(MINILIBX_PATH) clean
					$(RM) $(OBJS)

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					make -C $(MINILIBX_PATH) clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
