# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFTDIR = ./libft
SRCDIR = .
OBJDIR = ./obj
INCDIR = ./libft

# Files
NAME = ft_printf
LIBFT = $(LIBFTDIR)/libft.a

# List of .c files in the root directory
SRC = ft_printf.c parse_flags.c parse_width.c parse_precision.c parse_specifier.c apply_specifier.c
OBJ = $(SRC:.c=.o)

# The rule to build the final executable
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

# Rule for compiling .c files into .o files (objects)
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Include the libft functions
$(LIBFT):
	make -C $(LIBFTDIR)

# Clean up the object files
clean:
	rm -f $(OBJ)
	make -C $(LIBFTDIR) clean

# Remove all built files (object files, executables, etc.)
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

# Optional: run the bonus flag build (if you have any bonus target)
bonus: $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

