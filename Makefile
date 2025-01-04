LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
NAME = libftprintf.a

SRC = ft_printf_bonus.c ft_printf_formatter.c ft_printf_helpers.c ft_printf_utils.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)        # Build libft.a
	cp $(LIBFT) ./              # Copy libft.a to the current directory
	$(eval LIBFT_OBJ := $(shell ar t libft.a)) # Extract object file names from libft.a
	ar x libft.a                # Extract object files from libft.a
	ar rcs $(NAME) $(OBJ) $(LIBFT_OBJ) # Add all object files to libftprintf.a
	rm -f $(LIBFT_OBJ) libft.a  # Clean up extracted object files and copied libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

#SRC = ./ft_printf_bonus.c\
#	  ./ft_printf_helpers.c\
#	  ./ft_printf_utils.c\
#	  ./ft_printf_formatter.c
#
#OBJ = $(SRC:.c=.o)
#
#CC = cc
#
#CFLAGS = -Wall -Werror -Wextra
#
#LIB_NAME = ft
#
#DIR_LIBFT = ./libft
#
#LIBFT = $(DIR_LIBFT)/libft.a
#
#NAME = libftprintf.a
#
#%.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@
#
#$(NAME): $(OBJ)
#	$(MAKE) -C ./libft
#	ar rcs $(NAME) $(OBJ) ./libft/libft.a
#
#$(LIBFT):
#	$(MAKE) -C $(DIR_LIBFT)
#
#all: $(NAME)
#
#clean:
#	rm -f $(OBJ)
#	$(MAKE) -C $(DIR_LIBFT) clean
#
#fclean: clean
#	rm -f $(NAME)
#	$(MAKE) -C $(DIR_LIBFT) fclean
#
#re: fclean all
