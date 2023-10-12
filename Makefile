NAME = matrix
OBJS_DIR = Objs

FILES = main.cpp 

SRCS = $(addprefix Sources/, $(FILES))

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

# ===---===---===---===---===---===---===---===---===---===---===---===---

CFLAGS = -Wall -Wextra -Werror -std=c++11
INCLUDES = -I Includes

# ===---===---===---===---===---===---===---===---===---===---===---===---

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)/Sources

$(NAME): $(OBJS)
	c++ $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.cpp
	c++ $(CFLAGS) $(INCLUDES) -c $< -o $@

ex00: $(OBJS_DIR)
	c++ $(CFLAGS) $(INCLUDES) -c Sources/ex00.cpp -o $(OBJS_DIR)/ex00.o
	c++ $(CFLAGS) -o $(NAME) $(OBJS_DIR)/ex00.o
	./matrix

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./matrix

.PHONY: all clean fclean re run ex00
