# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 17:41:51 by rjeor-mo          #+#    #+#              #
#    Updated: 2019/09/28 23:10:43 by rjeor-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C=checker
NAME_PS=push_swap

VPATH=./

CC=gcc

HEADER_LIB= -I libft/

LIBFT= -L libft/ -lftprintf

IDIR=./libft

INCLUDES= -I$(IDIR)

HEADERS= $(HEADERS_C) $(HEADERS_PS)
HEADERS_C= get_next_line.h ft_pushswap.h
HEADERS_PS= ft_pushswap.h

CFLAGS=-Wall -Wextra -Werror $(INCLUDES)

RM= rm -f

SRC=$(SRCPS) $(SRCC)

SRCPS= main_stack.c ft_pushswap.c f_all.c f_all_s.c funcs3.c funcs2.c funcs.c my_stack_free.c\
       my_stack.c my_stack2.c n_commands.c n_commands_rev.c \
	   n_min_max.c pair_alg2.c n_push_one_back.c n_sort_three.c

SRCC= main_check.c ft_pushswap.c f_all.c f_all_s.c funcs3.c funcs2.c funcs.c my_stack_free.c \
      my_stack.c my_stack2.c get_next_line.c n_commands.c n_commands_rev.c \
	  n_min_max.c pair_alg2.c n_push_one_back.c n_sort_three.c

all: $(NAME_C) $(NAME_PS)

OBJC=$(SRCC:.c=.o)
OBJPS=$(SRCPS:.c=.o)
OBJ=$(OBJC) $(OBJPS)

$(NAME_C): $(OBJC) $(HEADERS_C)
	make -C libft
	@echo "CHECKER:"
	$(CC) $(CFLAGS) -o $(NAME_C) $(OBJC) $(LIBFT)

$(NAME_PS): $(OBJPS) $(HEADERS_PS)
	make -C libft
	@echo "PUSH_SWAP:"
	$(CC) $(CFLAGS) -o $(NAME_PS) $(OBJPS) $(LIBFT)

%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(OBJ)
	make -C libft clean

fclean: clean
	$(RM) $(NAME_C)
	$(RM) $(NAME_PS)
	make -C libft fclean

re: fclean all
