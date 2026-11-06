NAME        = lem_in
CC          = gcc
CFLAGS      = #-g -fsanitize=address #-Wall -Wextra -Werror 
IFLAGS		= -Iinclude

SRC_DIR     = src
INC_DIR     = include
OBJ_DIR     = obj

SRC         = $(wildcard $(SRC_DIR)/*.c)
OBJ         = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBS        = -lglfw -lGL -lGLEW


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) libft.a -o $(NAME) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(IFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
