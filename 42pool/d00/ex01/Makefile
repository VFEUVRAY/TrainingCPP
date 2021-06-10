CC =	g++ -W -Wall -ansi -pedantic
NAME =	phonebook
SRC =	misc.cpp			\
		contact.cpp			\
		add_contact.cpp		\
		search_contact.cpp	\
		phonebook.cpp
INC =	phonebook.hpp
OBJ =	$(SRC:%.cpp=%.o)
RM =	rm -f

$(NAME):	$(INC) $(OBJ)
		$(CC) $(INC) $(OBJ) -o $(NAME)
all:	$(NAME)
clean:
		$(RM) $(OBJ)
fclean:	clean
		$(RM) $(NAME)
re:		fclean all