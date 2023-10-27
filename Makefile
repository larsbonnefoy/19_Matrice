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

ex03: $(OBJS_DIR) $(OBJS)
	c++ $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/ex03.cpp -o $(OBJS_DIR)/ex03.o
	c++ $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_DIR)/ex03.o
	./matrix

ex04: $(OBJS_DIR) $(OBJS)
	c++ $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/ex04.cpp -o $(OBJS_DIR)/ex04.o
	c++ $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_DIR)/ex04.o
	./matrix

ex05: $(OBJS_DIR) $(OBJS)
	c++ $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/ex05.cpp -o $(OBJS_DIR)/ex05.o
	c++ $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_DIR)/ex05.o
	./matrix

ex06: $(OBJS_DIR) $(OBJS)
	c++ $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/ex06.cpp -o $(OBJS_DIR)/ex06.o
	c++ $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_DIR)/ex06.o
	./matrix


ex07: $(OBJS_DIR) $(OBJS)
	c++ $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/ex07.cpp -o $(OBJS_DIR)/ex07.o
	c++ $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_DIR)/ex07.o
	./matrix


ex08: $(OBJS_DIR) $(OBJS)
	c++ $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/ex08.cpp -o $(OBJS_DIR)/ex08.o
	c++ $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_DIR)/ex08.o
	./matrix

ex09: $(OBJS_DIR) $(OBJS)
	c++ $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/ex09.cpp -o $(OBJS_DIR)/ex09.o
	c++ $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_DIR)/ex09.o
	./matrix

ex10: $(OBJS_DIR) $(OBJS)
	c++ $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/ex10.cpp -o $(OBJS_DIR)/ex10.o
	c++ $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_DIR)/ex10.o
	./matrix

ex11: $(OBJS_DIR) $(OBJS)
	c++ $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/ex11.cpp -o $(OBJS_DIR)/ex11.o
	c++ $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_DIR)/ex11.o
	./matrix

ex12: $(OBJS_DIR) $(OBJS)
	c++ $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/ex12.cpp -o $(OBJS_DIR)/ex12.o
	c++ $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_DIR)/ex12.o
	./matrix

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./matrix

.PHONY: all clean fclean re run ex00 ex01 ex02 ex03 ex04 ex05 ex06 ex07 ex08 ex09
