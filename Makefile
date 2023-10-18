NAME = matrix
OBJS_DIR = Obj
SRC_DIR = Src

SRC = Vector.cpp

OBJS = $(addprefix $(OBJS_DIR)/, $(SRC:.cpp=.o))

# ===---===---===---===---===---===---===---===---===---===---===---===---

CFLAGS = -Wall -Wextra -Werror -std=c++11 -g
INCLUDES = -I Includes

# ===---===---===---===---===---===---===---===---===---===---===---===---

all: $(OBJS_DIR) $(OBJS)
	c++ $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/main.cpp -o $(OBJS_DIR)/main.o
	c++ $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_DIR)/main.o

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp
	c++ $(CFLAGS) $(INCLUDES) -c $< -o $@

ex00: $(OBJS_DIR) $(OBJS)
	c++ $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/ex00.cpp -o $(OBJS_DIR)/ex00.o
	c++ $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_DIR)/ex00.o
	./matrix

ex01: $(OBJS_DIR) $(OBJS)
	c++ $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/ex01.cpp -o $(OBJS_DIR)/ex01.o
	c++ $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_DIR)/ex01.o
	./matrix

ex02: $(OBJS_DIR) $(OBJS)
	c++ $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/ex02.cpp -o $(OBJS_DIR)/ex02.o
	c++ $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_DIR)/ex02.o
	./matrix

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./matrix

.PHONY: all clean fclean re run ex00 ex01 ex02
