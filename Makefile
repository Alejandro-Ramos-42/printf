# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFTDIR = ./libft
INCDIR = ./libft

# Target Names
NAME = libftprintf.a
LIBFT = $(LIBFTDIR)/libft.a

# Source Files
SRC = ./ft_printf.c\
	  ./apply_specifiers.c

OBJ = $(SRC:.c=.o)

#Bonus Files
BSRC = ./ft_printf_bonus.c\
	   ./parsing_bonus.c\
	   ./apply_specifiers_bonus.c\
	   ./ft_printf_bonus_c_s_u.c\
	   ./ft_printf_bonus_x_p.c\
	   ./ft_printf_bonus_d_i.c

BOBJ = $(BSRC:.c=.o)

# Create the static library for ft_printf
$(NAME): $(OBJ) $(LIBFT)
	@cp $(LIBFT) .
	#@ar x libft.a
	@ar rcs libft.a $(OBJ)
	mv libft.a $(NAME)
	#@rm -f *.o libft.a

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Build both libft and ft_printf libraries
all: $(LIBFT) $(NAME)

#Bonus rule
bonus: $(NAME) $(BOBJ)
	@cp $(LIBFT) .
	#@ar x libft.a
	@ar rcs libft.a $(BOBJ)
	mv libft.a $(NAME)

# Build libft first
$(LIBFT):
	make -C $(LIBFTDIR)

# Remove object files for ft_printf
clean:
	rm -f $(OBJ) $(BOBJ)
	make -C $(LIBFTDIR) clean

# Remove everything, including ft_printf library
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

# Rebuild everything
re: fclean all
