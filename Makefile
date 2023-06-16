NAME = parser

SRC_DIR = srcs/
OBJ_DIR = objs/
INC_DIR = includes/

INCS = -I$(INC_DIR)

SRC =	main.cpp \
		Request.cpp \
		IrcParser.cpp

OBJ := $(SRC:%.cpp=%.o)

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wfatal-errors
# CXXFLAGS = -std=c++98

all: $(NAME)

$(NAME): $(SRCS) $(OBJ_DIR) $(OBJS)
	@c++ $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@c++ $(CXXFLAGS) $(INCS) $< -c -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)