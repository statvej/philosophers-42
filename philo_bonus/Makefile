NAME = philo_bonus
SRC = src
INC = inc
OBJ = obj
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-I $(LIB_D) -I $(INC)
SRC_F = $(wildcard $(SRC)/*.c)
OBJ_F = $(SRC_F:.c=.o)
OBJS = $(subst $(SRC),$(OBJ),$(OBJ_F))

GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;34m
DEF_COLOR = \033[0;39m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $^ $(CFLAGS) -o $(NAME)
	@echo "$(GREEN) Philo compiled!$(DEF_COLOR)"

$(OBJ)/%.o:	$(SRC)/%.c $(OBJ)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): 
	@mkdir -p $(OBJ)
	@echo "$(BLUE)libft is done!$(DEF_COLOR)"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(YELLOW)Evrything was cleaned $(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re