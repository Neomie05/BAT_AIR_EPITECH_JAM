##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	window.c	\
		windo.c

OBJ 	=	$(SRC:.c=.o)

NAME 	=	 bat_air

all: 	$(NAME)

$(NAME):	$(OBJ)
	gcc $(SRC) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -o bat_air

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
