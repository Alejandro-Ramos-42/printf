# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 11:26:10 by aramos            #+#    #+#              #
#    Updated: 2025/02/21 11:27:02 by aramos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFTDIR = ./libft
INCDIR = ./libft

# Target Names
NAME = libftprintf.a
LIBFT = $(LIBFTDIR)/libft.a

# Files
SRC = ./ft_printf.c\
	   ./parsing.c\
	   ./apply_specifiers.c\
	   ./ft_printf_c_s_u.c\
	   ./ft_printf_x_p.c\
	   ./ft_printf_d_i.c

OBJ = $(SRC:.c=.o)

# Create the static library for ft_printf
$(NAME): $(OBJ) $(LIBFT)
	@cp $(LIBFT) libft.a
	@ar rcs libft.a $(OBJ)
	@mv libft.a $(NAME)
	@rm *.o

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
	rm -f $(OBJ) $(BOBJ)
	make -C $(LIBFTDIR) clean

# Remove everything, including ft_printf library
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

# Rebuild everything
re: fclean all
