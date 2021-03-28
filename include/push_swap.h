#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "../src/get_next_line.h"

typedef struct		s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_inst
{
	char			*op;
	struct s_inst	*next;
	struct s_inst	*prev;
}					t_inst;

typedef struct		s_ps_env
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_inst			*inst;
	int				argc;
	char			**argv;
}					t_ps_env;

t_stack     		*create_stack(int data);
void				push_back(t_stack **root, int data);
void				print_stack_a(t_ps_env *ps_env);
void    			start_checker(t_ps_env *ps_env);
t_ps_env    		*init_checker(int argc, char **argv);
int					back(t_stack *stack);
void    			do_op(t_ps_env *ps_env, char *line);
void				swap_a(t_ps_env *ps_env);
t_stack				*getStack(t_stack **root, int data);
void				rotate_a(t_ps_env *ps_env);
void				push_front(t_stack **root, int data);
#endif
