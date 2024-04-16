NAME = bsp

SRC = Fixed.cpp Point.cpp bsp.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXCXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXCXXFLAGS) $(SRC) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXCXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all