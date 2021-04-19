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
	int				visual;
	int 			len_a;
	int 			len_b;
	char			**argv;
}					t_ps_env;

t_stack     		*create_stack(int data);
t_inst				*create_inst(char *op);
void				push_back_inst(t_inst **root, char *op);
void				check_if_stack_is_sorted(t_ps_env *ps_env);
int					is_valid(t_ps_env *ps_env);
void				start_checker(t_ps_env *ps_env);
void				push_back(t_stack **root, int data);
void				print_stack_a(t_ps_env *ps_env);
t_ps_env    		*init_checker(int argc, char **argv);
int					back(t_stack *stack);
void    			do_op(t_ps_env *ps_env, char *line);
void				swap_a(t_ps_env *ps_env);
void				swap_b(t_ps_env *ps_env);
void				push_a(t_ps_env *ps_env);
void				push_b(t_ps_env *ps_env);
void				rotate_a(t_ps_env *ps_env);
void				rotate_b(t_ps_env *ps_env);
void				reverse_rotate_a(t_ps_env *ps_env);
void				reverse_rotate_b(t_ps_env *ps_env);
void				swap_both(t_ps_env *ps_env);
void				reverse_rotate_both(t_ps_env *ps_env);
void				rotate_both(t_ps_env *ps_env);
t_stack				*getStack(t_stack **root, int data);
void				rotate_a(t_ps_env *ps_env);
void				push_front(t_stack **root, int data);
int					get_stack_len(t_ps_env *ps_env, char stack_name);
void				push_swap(t_ps_env *ps_env);
t_stack				*getStackPos(t_stack **root, int pos);
#endif
