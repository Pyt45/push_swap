NAME := checker

PUSH_SWAP_LIB := push_swap.a

SRCS := src/stack_utils.c src/push_swap.c src/checker_init.c \
		src/get_next_line.c src/get_next_line_utils.c 

FLAGS := 

OBJS := $(SRCS:.c=.o)

INC := include

MAIN := src/main.c

all: $(NAME)

$(NAME): $(OBJS) $(MAIN) $(INC)/push_swap.h
	@ar rcs $(PUSH_SWAP_LIB) $(OBJS)
	@gcc $(MAIN) $(PUSH_SWAP_LIB) $(OBJS) -o $(NAME)
	@echo "\033[0;32m[INFO]: \033[0mSUCCESS!"

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@ -I $(INC)

clean:
	@rm -rf $(OBJS)
	@echo "\033[0;32m[INFO]:\033[0m Objects removed!"

fclean: clean
	@rm -rf $(PUSH_SWAP_LIB)
	@rm -rf $(NAME)
	@echo "\033[0;32m[INFO]:\033[0m $(NAME) removed!"

re: fclean clean