##
## EPITECH PROJECT, 2019
## MUL_my_rpg_2018
## File description:
## Makefile
##

NAME	= program

CC	= gcc

RM	= rm -f

SRCS	= ./my/compteurdizaine.c \
	  ./my/cpy_replace_strarg.c \
	  ./my/debug.c \
	  ./my/find_arg_strarg.c \
	  ./my/float2char.c \
	  ./my/get_next_line.c \
	  ./my/get_strarg_float.c \
	  ./my/get_strarg_int.c \
	  ./my/get_strarg_str.c \
	  ./my/int2char.c \
	  ./my/match_str.c \
	  ./my/my_f_puiss.c \
	  ./my/my_f_puiss_float.c \
	  ./my/my_getnbr.c \
	  ./my/my_printf.c \
	  ./my/my_put_nbr.c \
	  ./my/my_putchar.c \
	  ./my/my_putint.c \
	  ./my/my_putnbr.c \
	  ./my/my_putnbr_long.c \
	  ./my/my_putnbr_short.c \
	  ./my/my_putstr.c \
	  ./my/my_strcpy.c \
	  ./my/my_strlen.c \
	  ./my/replace_strarg_float.c \
	  ./my/replace_strarg_int.c \
	  ./my/replace_strarg_str.c \
	  ./my/strtab_tools.c \
	  ./my/to_strarg_char.c \
	  ./my/to_strarg_float.c \
	  ./my/to_strarg_int.c \
	  ./my/to_strtab_char.c \
	  ./my/to_strtab_int.c \
	  ./my/tools_1.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./../include/
CFLAGS += -Wall -Wextra

all: $(OBJS)
	ar rc libmy.a $(OBJS)

clean:
	$(RM) $(OBJS)

debug: CFLAGS += -g
debug: re

fclean: clean
	$(RM) libmy.a

re: fclean all