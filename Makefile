NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src
SUB_MAIN = $(addprefix $(SRC_DIR)/main_func/,main.c init_all.c)
SUB_ARG = $(addprefix $(SRC_DIR)/check_info/,check_general.c check_integer.c)
SUB_UTILS = $(addprefix $(SRC_DIR)/utils/,utils.c)
SUB_MEM = $(addprefix $(SRC_DIR)/mem_mani/,allocate.c)

SRC = $(SUB_MAIN) $(SUB_ARG) $(SUB_UTILS) $(SUB_MEM)

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
