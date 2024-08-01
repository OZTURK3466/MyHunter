##
## EPITECH PROJECT, 2023
## printf
## File description:
## makefile
##

NAME	=	my_hunter

SRCS	=	lib/my/my_putstr.c	\
			lib/my/my_putchar.c	\
			lib/my/my_put_nbr.c	\
			lib/my/my_strlen.c	\
			lib/my/my_strcpy.c	\
			lib/my/my_putfloat.c \
			lib/my/unsigned_nbr.c \
			lib/my/my_putnbr_base.c \
			lib/my/my_compute_power_rec.c \
			lib/my/my_put_e.c \
			lib/my/len_nbr.c \
			lib/my/verif_flags.c \
			lib/my/my_printf.c	\
			lib/my/my_getnbr.c	\
			help.c	\
			init_var.c	\
			moov.c	\
			menu.c	\
			my_hunter.c	\
			display.c	\
			main.c	\
			display_aide.c	\


OBJS	=	$(SRCS:.c=.o)

LFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJS)
		gcc -o $(NAME) $(OBJS) $(LFLAGS)

clean:
	rm -f $(OBJS)
	rm -f *~
	rm -f lib/my/*~
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f $(NAME)

re: fclean all
