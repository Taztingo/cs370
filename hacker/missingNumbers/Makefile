#Makefile for MissingNumbers Problem
NAME=MissingNumbers
SRC=main.c
OBJ=$(SRC:.c=.o)
RM=rm -f
LIBPATH=
LIBS=
# Begin Commands
all:$(OBJ)
	cc $(OBJ) $(LIBS) -Wall -pedantic-errors -o $(NAME)

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *.core

fclean: clean
	-$(RM) $(LIBPATH)/$(NAME)

re: fclean all