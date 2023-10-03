NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src
SUB_MAIN = $(addprefix $(SRC_DIR)/main/,main.c init_all.c allocate.c routine.c)
SUB_ARG = $(addprefix $(SRC_DIR)/check_info/,check_general.c)
SUB_UTILS = $(addprefix $(SRC_DIR)/utils/,utils.c utils2.c)

SRC = $(SUB_MAIN) $(SUB_ARG) $(SUB_UTILS)

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%o: %c
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)	

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
