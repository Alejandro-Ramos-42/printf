SRC = ./ft_printf_bonus.c\
	  ./ft_print_helpers.c\
	  ./ft_printf_utils.c\
	  ./ft_printf_formatter.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS += -Wall -Werror -Wextra -I. -I$(DIR_LIB)

LIB_NAME = ft

DIR_LIBFT = ./libft

NAME = libftprintf.a

$(DIR_LIBFT)/libft.a:
	$(MAKE) -C $(DIR_LIBFT)

$(NAME): $(OBJ) $(DIR_LIBFT)/libft.a
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(DIR_LIBFT) -l$(LIB_NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
