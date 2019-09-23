NAME_C=checker
NAME_PS=push_swap

VPATH=./

CC=gcc

HEADER_LIB= -I libft/

LIBFT= -L libft/ -lftprintf

IDIR=./libft

INCLUDES= -I$(IDIR)

HEADERS_C= get_next_line.h ft_pushswap.h
HEADERS_PS= ft_pushswap.h

#CFLAGS=-Wall -Wextra -Werror $(INCLUDES)
CFLAGS=-Wall -Wextra $(INCLUDES)

RM= rm -f

SRC=$(SRCPS) $(SRCC)

SRCPS= main_stack.c ft_pushswap.c f_all.c f_all_s.c funcs3.c funcs2.c funcs.c my_stack_free.c\
       my_stack.c my_stack2.c pair_alg.c pair_alg2.c

SRCC= main_check.c ft_pushswap.c f_all.c f_all_s.c funcs3.c funcs2.c funcs.c my_stack_free.c \
      my_stack.c my_stack2.c pair_alg.c pair_alg2.c get_next_line.c

all: $(NAME_C) $(NAME_PS)

OBJ=$(OBJC) $(OBJPW)
OBJC=$(SRCC:.c=.o)
OBJPS=$(SRCPS:.c=.o)

$(NAME_C): $(OBJC) $(HEADERS_C)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME_C) $(OBJC) $(LIBFT)

$(NAME_PS): $(OBJPS) $(HEADERS_PS)
	make -C libft
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
