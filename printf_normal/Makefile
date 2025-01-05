# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFTDIR = ./libft
INCDIR = ./libft

# Target Names
NAME = libftprintf.a
LIBFT = $(LIBFTDIR)/libft.a

# Source Files in the Root Directory
SRC = ./ft_printf.c\
	  ./apply_specifiers.c

OBJ = $(SRC:.c=.o)

# Create the static library for ft_printf
$(NAME): $(OBJ) $(LIBFT)
	@cp $(LIBFT) .
	@ar x libft.a
	@ar rcs $(NAME) $(OBJ) *.o
	@rm -f *.o libft.a

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Build both libft and ft_printf libraries
all: $(LIBFT) $(NAME)

# Build libft first
$(LIBFT):
	make -C $(LIBFTDIR)

# Remove object files for ft_printf
clean:
	rm -f $(OBJ)
	make -C $(LIBFTDIR) clean

# Remove everything, including ft_printf library
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

# Rebuild everything
re: fclean all
