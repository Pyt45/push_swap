#include "../include/push_swap.h"

t_ps_env    *init_checker(int argc, char **argv)
{
    t_ps_env    *ps_env;

    if (!(ps_env = (t_ps_env *)malloc(sizeof(t_ps_env))))
        return (NULL);
    if (!(ps_env->stack_a = (t_stack *)malloc(sizeof(t_stack))))
        return (NULL);
    if (!(ps_env->stack_b = (t_stack *)malloc(sizeof(t_stack))))
        return (NULL);
    ps_env->stack_a = NULL;
    ps_env->stack_b = NULL;
    ps_env->inst = NULL;
    ps_env->argc = argc;
    ps_env->argv = argv;

    return (ps_env);
}

void    swap_a(t_ps_env *ps_env)
{
    int     tmp;

    tmp = ps_env->stack_a->data;
    ps_env->stack_a->data = ps_env->stack_a->next->data;
    ps_env->stack_a->next->data = tmp;
}

void    rotate_a(t_ps_env *ps_env)
{
	// int		tmp;
// 1 2 3 4 , 2 3 4 1
	t_stack	*tmp;
	t_stack *new_head;

	tmp = ps_env->stack_a;
	new_head = ps_env->stack_a->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ps_env->stack_a;
	if (ps_env->stack_a->prev)
		ps_env->stack_a->prev = tmp;
	ps_env->stack_a->next = NULL;
	ps_env->stack_a = new_head;
}

void    push_b(t_ps_env *ps_env)
{
    // if (!ps_env->stack_b)
    push_back(&ps_env->stack_b, ps_env->stack_a->data);
    return ;
}

void    push_a(t_ps_env *ps_env)
{
    return ;
}

void    rotate_b(t_ps_env *ps_env)
{
    return ;
}

void    swap_b(t_ps_env *ps_env)
{
    return ;
}

void    swap_both(t_ps_env *ps_env)
{
    return ;
}

void    reverse_rotate_a(t_ps_env *ps_env)
{
    return ;
}

void    reverse_rotate_b(t_ps_env *ps_env)
{
    return ;
}

void    reverse_rotate_both(t_ps_env *ps_env)
{
    return ;
}

void    rotate_both(t_ps_env *ps_env)
{
    return ;
}


void    do_op(t_ps_env *ps_env, char *line)
{
    if (!strcmp(line, "sa"))
        swap_a(ps_env);
    else if (!strcmp(line, "ra"))
        rotate_a(ps_env);
    else if (!strcmp(line, "rra"))
        reverse_rotate_a(ps_env);
    else if (!strcmp(line, "pa"))
        push_a(ps_env);
    else if (!strcmp(line, "sb"))
        swap_b(ps_env);
    else if (!strcmp(line, "rb"))
        rotate_b(ps_env);
    else if (!strcmp(line, "rrb"))
        reverse_rotate_b(ps_env);
    else if (!strcmp(line, "pb"))
        push_b(ps_env);
    else if (!strcmp(line, "ss"))
        swap_both(ps_env);
    else if (!strcmp(line, "rr"))
        rotate_both(ps_env);
    else if (!strcmp(line, "rrr"))
        reverse_rotate_both(ps_env);
    else
        return ;
}

void    start_checker(t_ps_env *ps_env)
{
    int     i;
    int     r;
    char    *line;

    i = 0;
    while (++i < ps_env->argc)
        push_back(&ps_env->stack_a, atoi(ps_env->argv[i]));
    print_stack_a(ps_env);
    r = get_next_line(0, &line);
    while (r)
    {
        if (!strcmp(line, "end"))
            break ;
        do_op(ps_env, line);
        r = get_next_line(0, &line);
    }
    // printf("%d\n", back(ps_env->stack_a));
	// printf("l = %d\n", getStack(&ps_env->stack_a, back(ps_env->stack_a))->data);
    print_stack_a(ps_env);
   // printf("%s\n", line);
}