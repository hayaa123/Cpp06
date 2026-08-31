NAME = realType
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp functions.cpp Base.cpp
OBJ = $(SRC:.cpp=.o) 

all: $(NAME)

$(NAME): $(OBJ) ClassA.hpp ClassB.hpp ClassC.hpp Base.hpp functions.hpp
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re%