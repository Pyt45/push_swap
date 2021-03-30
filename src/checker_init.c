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
    ps_env->visual = 0;
    ps_env->len_a = 0;
    ps_env->len_b = 0;

    return (ps_env);
}

void    destroy_ps_env(t_ps_env *ps_env)
{

}

void    push_swap_ko(t_ps_env *ps_env)
{
    destroy_ps_env(ps_env);
    // write(2, "ko\n", 3);
    printf("\033[1;31mko\033[0m\n");
    exit(EXIT_SUCCESS);
}

void    swap_a(t_ps_env *ps_env)
{
    if (!ps_env->stack_a || !ps_env->stack_b->next)
        destroy_ps_env(ps_env);
    t_stack *new_head;

    new_head = ps_env->stack_a->next;
    ps_env->stack_a->next = new_head->next;
    ps_env->stack_a->next->prev = ps_env->stack_a;
    new_head->next = ps_env->stack_a;
    ps_env->stack_a->prev = new_head;
    ps_env->stack_a = new_head;
}

void    rotate_a(t_ps_env *ps_env)
{
    if (!ps_env->stack_a || !ps_env->stack_a->next)
        push_swap_ko(ps_env);
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
    if (!ps_env->stack_a)
        push_swap_ko(ps_env);
    t_stack *del;
    push_front(&ps_env->stack_b, ps_env->stack_a->data);
    ps_env->len_a--;
    ps_env->len_b++;
    del = ps_env->stack_a;
    if (ps_env->stack_a && ps_env->stack_a->next)
        ps_env->stack_a = ps_env->stack_a->next;
    if (ps_env->stack_a->prev)
        ps_env->stack_a->prev = NULL;
    free(del);
}

void    push_a(t_ps_env *ps_env)
{
	t_stack *del;
    if (!ps_env->stack_b)
        push_swap_ko(ps_env);
    push_front(&ps_env->stack_a, ps_env->stack_b->data);
    ps_env->len_a++;
    ps_env->len_b--;
    del = ps_env->stack_b;
    if (ps_env->stack_b && ps_env->stack_b->next)
        ps_env->stack_b = ps_env->stack_b->next;
    if (ps_env->stack_b->prev)
        ps_env->stack_b->prev = NULL;
    free(del);
}

void    rotate_b(t_ps_env *ps_env)
{
    if (!ps_env->stack_b || !ps_env->stack_b->next)
        push_swap_ko(ps_env);
    t_stack *tmp;
    t_stack *new_head;

    tmp = ps_env->stack_b;
    new_head = ps_env->stack_b->next;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = ps_env->stack_b;
    if (ps_env->stack_b->prev)
        ps_env->stack_b->prev = tmp;
    ps_env->stack_b->next = NULL;
    ps_env->stack_b = new_head;
}

void    swap_b(t_ps_env *ps_env)
{
    if (!ps_env->stack_b || !ps_env->stack_b->next)
        destroy_ps_env(ps_env);
    t_stack *new_head;

    new_head = ps_env->stack_b->next;
    ps_env->stack_b->next = new_head->next;
    new_head->next = ps_env->stack_b;
    ps_env->stack_b = new_head;
}

void    swap_both(t_ps_env *ps_env)
{
    if (!ps_env->stack_a || !ps_env->stack_a->next
    || !ps_env->stack_b || !ps_env->stack_b->next)
        destroy_ps_env(ps_env);
    swap_a(ps_env);
    swap_b(ps_env);
}

void    reverse_rotate_a(t_ps_env *ps_env)
{
    if (!ps_env->stack_a || !ps_env->stack_a->next)
        push_swap_ko(ps_env);
    t_stack *tmp;
    t_stack *new_head;

    tmp = ps_env->stack_a;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = ps_env->stack_a;
    tmp->prev->next = NULL;
    ps_env->stack_a->prev = tmp;
    ps_env->stack_a = tmp;
    return ;
}

void    reverse_rotate_b(t_ps_env *ps_env)
{
    if (!ps_env->stack_b || !ps_env->stack_b->next)
        push_swap_ko(ps_env);
    t_stack *tmp;
    t_stack *new_head;

    tmp = ps_env->stack_b;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = ps_env->stack_b;
    tmp->prev->next = NULL;
    ps_env->stack_b->prev = tmp;
    ps_env->stack_b = tmp;
    return ;
}

void    reverse_rotate_both(t_ps_env *ps_env)
{
    if (!ps_env->stack_a || !ps_env->stack_a->next
    || !ps_env->stack_b || !ps_env->stack_b->next)
        push_swap_ko(ps_env);
    reverse_rotate_a(ps_env);
    reverse_rotate_b(ps_env);
    return ;
}

void    rotate_both(t_ps_env *ps_env)
{
    if (!ps_env->stack_a || !ps_env->stack_a->next
    ||!ps_env->stack_b || !ps_env->stack_b->next)
        push_swap_ko(ps_env);
    rotate_a(ps_env);
    rotate_b(ps_env);
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
    if (!strcmp(ps_env->argv[1], "-v"))
        ps_env->visual = 1;
    i = 1;
    while (++i < ps_env->argc)
        push_back(&ps_env->stack_a, atoi(ps_env->argv[i]));
    (ps_env->visual) ? print_stack_a(ps_env) : 0;
    r = get_next_line(0, &line);
    while (r)
    {
        if (!strcmp(line, "end"))
            break ;
        do_op(ps_env, line);
        (ps_env->visual) ? print_stack_a(ps_env) : 0;
        r = get_next_line(0, &line);
    }
}