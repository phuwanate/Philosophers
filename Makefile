NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src
SRC_SUBDIRS = check_arguments utils
SRC = $(foreach dir,$(SRC_SUBDIRS),$(wildcard $(SRC_DIR)/$(dir)/*.c))
OBJS = $(SRC:.c=.o)

all: $(NAME)

%o: %c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean: 
	rm -f $(OBJS)	

fclean : clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
