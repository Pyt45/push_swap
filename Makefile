NAME := push_swap

PUSH_SWAP_LIB := push_swap.a

SRCS := src/stack_init.c src/push_swap.c

FLAGS := 

OBJS := $(SRCS:.c=.o)

INC := include

MAIN := src/main.c

all: $(NAME)

$(NAME): $(OBJS) $(MAIN) $(INC)/push_swap.h
	@ar rcs $(PUSH_SWAP_LIB) $(OBJS)
	@gcc $(MAIN) $(PUSH_SWAP_LIB) $(OBJS) -o $(NAME)
	@echo "\033[0.32mSUCCESS!\33[0m"

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@ -I $(INC)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(PUSH_SWAP_LIB)
	@rm -rf $(NAME)

re: fclean clean