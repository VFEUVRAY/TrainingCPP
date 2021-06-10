CC =	g++ -W -Wall -ansi -pedantic
NAME =	megaphone
SRC =	megaphone.cpp
OBJ =	$(SRC:%.cpp=%.o)
RM =	rm -f

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)
all:	$(NAME)
clean:
		$(RM) $(OBJ)
fclean:	clean
		$(RM) $(NAME)
re:		fclean all