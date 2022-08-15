NAME = libftprintf.a
LIB = libft.a
LIB_D = libft
SRC = src
INC = inc
OBJ = obj
AR = ar rcs
CC = clang
CFLAGS =  -I $(INC) #-Wall -Wextra -Werror
SRC_F = $(wildcard $(SRC)/*.c)
INC_F = $(wildcard $(INC)/*.h)
OBJ_F = $(SRC_F:.c=.o)
OBJS = $(subst $(SRC),$(OBJ),$(OBJ_F))

all: $(NAME)

test: $(OBJS) $(LIB_D)/$(LIB)
	@$(CC) $(CFLAGS) $^ -o $@

$(NAME): $(OBJS)
	@make -C $(LIB_D)
	@cp $(LIB_D)/$(LIB) .
	@mv $(LIB) $(NAME)
	@$(AR) $(NAME) $(OBJS) 

$(OBJ)/%.o:    $(SRC)/%.c $(OBJ)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): 
	@mkdir -p $(OBJ)

bonus: all

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB_D)
re: fclean all