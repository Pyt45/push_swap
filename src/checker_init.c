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
	if (!(ps_env->inst = (t_inst *)malloc(sizeof(t_inst))))
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
    printf("\033[1;31mKO\033[0m\n");
    exit(EXIT_SUCCESS);
}

void    swap_a(t_ps_env *ps_env)
{
    if (!ps_env->stack_a || !ps_env->stack_a->next)
        push_swap_ko(ps_env);
    t_stack *new_head;

    new_head = ps_env->stack_a->next;
    ps_env->stack_a->next = new_head->next;
    ps_env->stack_a->next->prev = ps_env->stack_a; // h
    new_head->next = ps_env->stack_a;
    ps_env->stack_a->prev = new_head;
    ps_env->stack_a = new_head;
	if (ps_env->visual)
		print_stack_a(ps_env);
}

// void	swap_b(t_ps_env *ps_env)
// {
// 	if (!ps_env->stack_b || !ps_env->stack_b->next)
// 		push_swap_ko(ps_env);
// 	t_stack *new_head;

// 	new_head = ps_env->stack_b->next;
// 	ps_env->stack_b->next = new_head->next;
// 	// ps_env->stack_b->next->prev = ps_env->stack_b;
// 	new_head->next = ps_env->stack_b;
// 	ps_env->stack_b->prev = new_head;
// 	ps_env->stack_b = new_head;
// 	if (ps_env->visual)
// 		print_stack_a(ps_env);
// }

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
    if (!ps_env->stack_a->prev)
        ps_env->stack_a->prev = tmp;
    ps_env->stack_a->next = NULL;
    ps_env->stack_a = new_head;
	if (ps_env->visual)
		print_stack_a(ps_env);
}

// 3 -> 2 -> 1 | a = a->next | 1
// 3
// 2
// 1

void    push_b(t_ps_env *ps_env)
{
    t_stack **tmp;

    if (!ps_env->stack_a)
		return ;
    // push_swap_ko(ps_env);
	tmp = &ps_env->stack_a;
	if ((*tmp) && (*tmp)->next)
	{
		// printf("wow\n");
		if (*tmp && (*tmp)->next)
    		push_front(&ps_env->stack_b, (*tmp)->data);
		// ps_env->len_a--;
		// ps_env->len_b++;
		if ((*tmp) && (*tmp)->next)
		{
			// printf("hi\n");
			*tmp = (*tmp)->next;
			// ps_env->stack_a = ps_env->stack_a->next;
		}
		if ((*tmp)->prev)
		{
			// printf("op\n");
			(*tmp)->prev = NULL;
		}
		// free(tmp);
		//printf("d = %d\n", ps_env->stack_a->data);
		// free((*del));
		// ps_env->stack_a = NULL;
		// (*del) = NULL;
		/*del = ps_env->stack_a->next;
		ps_env->stack_a->next = ps_env->stack_b;
		ps_env->stack_b = ps_env->stack_a;
		ps_env->stack_a = del;*/
	}
	else if ((*tmp) && (*tmp)->next == NULL)
	{
		push_front(&ps_env->stack_b, (*tmp)->data);
		free((*tmp));
		(*tmp) = NULL;
	}
	if (ps_env->visual)
		print_stack_a(ps_env);
}

void    push_a(t_ps_env *ps_env)
{
	t_stack **tmp;

    if (!ps_env->stack_b)
		return ;
	tmp = &ps_env->stack_b;
	if ((*tmp) && (*tmp)->next)
	{
		// printf("wow\n");
		if (*tmp && (*tmp)->next)
    		push_front(&ps_env->stack_a, (*tmp)->data);
		// ps_env->len_a--;
		// ps_env->len_b++;
		if ((*tmp) && (*tmp)->next)
		{
			// printf("hi\n");
			*tmp = (*tmp)->next;
			// ps_env->stack_a = ps_env->stack_a->next;
		}
		if ((*tmp)->prev)
		{
			// printf("op\n");
			(*tmp)->prev = NULL;
		}
		// free(tmp);
		//printf("d = %d\n", ps_env->stack_a->data);
		// free((*del));
		// ps_env->stack_a = NULL;
		// (*del) = NULL;
		/*del = ps_env->stack_a->next;
		ps_env->stack_a->next = ps_env->stack_b;
		ps_env->stack_b = ps_env->stack_a;
		ps_env->stack_a = del;*/
	}
	else if ((*tmp) && (*tmp)->next == NULL)
	{
		push_front(&ps_env->stack_a, (*tmp)->data);
		free((*tmp));
		(*tmp) = NULL;
	}
    // push_swap_ko(ps_env);
	/*if (ps_env->stack_b)
   		push_front(&ps_env->stack_a, ps_env->stack_b->data);
    // ps_env->len_a++;
    // ps_env->len_b--;
    del = ps_env->stack_b;
    if (ps_env->stack_b && ps_env->stack_b->next)
        ps_env->stack_b = ps_env->stack_b->next;
    if (ps_env->stack_b->prev)
        ps_env->stack_b->prev = NULL;
    free(del);*/
	if (ps_env->visual)
		print_stack_a(ps_env);
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
    if (!ps_env->stack_b->prev)
        ps_env->stack_b->prev = tmp;
    ps_env->stack_b->next = NULL;
    ps_env->stack_b = new_head;
	if (ps_env->visual)
		print_stack_a(ps_env);
}

void    swap_b(t_ps_env *ps_env)
{
	if (!ps_env->stack_b || !ps_env->stack_b->next)
		push_swap_ko(ps_env);
	t_stack *new_head;

    new_head = ps_env->stack_b->next;
    ps_env->stack_b->next = new_head->next;
	 ps_env->stack_b->next->prev = ps_env->stack_b; // h 3
    new_head->next = ps_env->stack_b;
	ps_env->stack_b->prev = new_head;
    ps_env->stack_b = new_head;
	if (ps_env->visual)
		print_stack_a(ps_env);
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
	tmp->prev = NULL;
    ps_env->stack_a = tmp;
	if (ps_env->visual)
		print_stack_a(ps_env);
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
	tmp->prev = NULL; // h 2
    ps_env->stack_b = tmp;
	if (ps_env->visual)
		print_stack_a(ps_env);
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
	{
		printf("\033[1;31mError\033[0m\n");
		exit(1);
	}
}

void	check_if_stack_is_sorted(t_ps_env *ps_env)
{
	// ra, rb,
	int		count;
	int		stack_len;
	count = 1;
	if (ps_env->stack_a && !ps_env->stack_b)
	{
		stack_len = get_stack_len(ps_env, 'a');
		while (ps_env->stack_a->next)
		{
			if (ps_env->stack_a->data < ps_env->stack_a->next->data)
				count++;
			ps_env->stack_a = ps_env->stack_a->next;
		}
	}
	if (count == stack_len)
		printf("\033[1;32mOK\033[0m\n");
	else
		printf("\033[1;31mKO\033[0m\n");
}

static void	ft_free(char **data, int argc)
{
	int		i;

	i = -1;
	while (++i < argc - 1)
	{
		if (data[i])
			free(data[i]);
	}
	free(data);
}

int		is_valid(t_ps_env *ps_env)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	j = 1;
	if (ps_env->visual)
	{
		tmp = (char **)malloc(sizeof(char *) * (ps_env->argc - 1));
		while (++i < ps_env->argc - 2)
		{
			if (i == 0)
				tmp[0] = ft_strdup(ps_env->argv[2]);
			else
				tmp[i] = ft_strdup(ps_env->argv[i + j + 1]);
		}
		tmp[i] = NULL;
		j = -1;
		while (++j < ps_env->argc - 2)
		{
			i = -1;
			while (++i < (int)ft_strlen(tmp[j]))
			{
				if (tmp[j][i] < '0' || tmp[j][i] > '9')
					return (0);
			}
		}
		ft_free(tmp, ps_env->argc - 1);
	}
	else
	{
		tmp = (char **)malloc(sizeof(char *) * ps_env->argc);
		while (++i < ps_env->argc - 1)
			tmp[i] = ft_strdup(ps_env->argv[i + 1]);
		tmp[i] = NULL;
		j = -1;
		while (++j < ps_env->argc - 1)
		{
			i = -1;
			while (++i < (int)ft_strlen(tmp[j]))
			{
				if (tmp[j][i] < '0' || tmp[j][i] > '9')
					return (0);
			}
		}
		ft_free(tmp, ps_env->argc);
	}
	return (1);
}

void    start_checker(t_ps_env *ps_env)
{
    int     i;
    int     r;
    char    *op;

    i = 0;
    if (!strcmp(ps_env->argv[1], "-v"))
        ps_env->visual = 1;
    i = 1;
	if (ps_env->argc != 3)
	{
		if (!is_valid(ps_env))
		{
			printf("\033[1;31mError\033[0m\n");
			return ;
		}
	}
	// else
	// {
		// Do Something
	// }
    while (++i < ps_env->argc)
        push_back(&ps_env->stack_a, atoi(ps_env->argv[i]));
    // ps_env->len_a = get_stack_len(ps_env, 'a');
	ps_env->len_a = 10;
    (ps_env->visual) ? print_stack_a(ps_env) : 0;
    r = 1;
	// system("clear");
    while (r)
    {
        r = get_next_line(0, &op);
        if (!strcmp(op, "end"))
		{
			check_if_stack_is_sorted(ps_env);
            break ;
		}
		/*if (r == 0)
		{
			check_if_stack_is_sorted(ps_env);
            break ;
		}*/
        do_op(ps_env, op);
        // (ps_env->visual) ? print_stack_a(ps_env) : 0;
    }
}