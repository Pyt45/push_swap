#include "../include/push_swap.h"

void	print_stack_a(t_ps_env *ps_env)
{
	t_stack *tmp_a = ps_env->stack_a;
	t_stack *tmp_b = ps_env->stack_b;

	printf("-------------------------------------------------\n");
	printf("Init a and b:\n");
	while (tmp_a || tmp_b)
	{
		/*
		if (tmp_b)
			printf("%d %d\n", tmp_a->data, tmp_b->data);
		else
			printf("%d\n", tmp_a->data);
		(tmp_b) ? tmp_b = tmp_b->next : 0;
		tmp_a = tmp_a->next;
		*/
		tmp_a != NULL ? printf("|%*d|", ps_env->len_a + 1, tmp_a->data) :
		printf("|%*c|", ps_env->len_a + 2, 0);
		tmp_b != NULL ? printf("|%*d|\n", ps_env->len_a, tmp_b->data) :
		printf("|%*c|\n", ps_env->len_a + 1, 0);

		tmp_a != NULL ? tmp_a = tmp_a->next : 0;
		tmp_b != NULL ? tmp_b = tmp_b->next : 0;
		// ps_env->stack_a = ps_env->stack_a->next;
	}
	printf("|%*c||%*c|\n", ps_env->len_a + 1, 'A', ps_env->len_a, 'B');
	printf("-------------------------------------------------\n");
	// while (tmp)
	//{
	//	printf("stack-prev(%d) : %d\n", i--, tmp->data);
	//	tmp = tmp->prev;
	//}
}

int		main(int argc, char **argv)
{
	t_ps_env	*ps_env;
	int			i;

	i = 1;
	if (argc == 1)
	{
		printf("Usage : [./checker] [option] [range]\n");
		return (-1);
	}
	if (!(ps_env = init_checker(argc, argv)))
		return (-1);
	start_checker(ps_env);
	// while (++i < ps_env->argc)
	// 	push_back(&ps_env->stack_a, atoi(ps_env->argv[i]));
	// push_swap(ps_env);
}
