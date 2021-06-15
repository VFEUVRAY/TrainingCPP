CC =	g++
NAME =	replace
SRC =	main.cpp			\
		replaceOccurrence.cpp
OBJ =	$(SRC:%.cpp=%.o)
HED =	replace.hpp
RM =	rm -f

$(NAME):	$(HED) $(OBJ)
		$(CC) $(HED) $(OBJ) -o $(NAME)
all:	$(NAME)
clean:
		$(RM) $(OBJ)
fclean:	clean
		$(RM) $(NAME)
re:		fclean all
