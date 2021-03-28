#include "../include/push_swap.h"

void	print_stack_a(t_ps_env *ps_env)
{
	t_stack *tmp_a = ps_env->stack_a;
	t_stack *tmp_b = ps_env->stack_b;

	printf("Init a and b:\n");
	while (tmp_a)
	{
		if (tmp_b)
		{
			printf("%d %d\n", tmp_a->data, tmp_b);
			tmp_b = tmp_b->next;
		}
		else
			printf("%d\n", tmp_a->data);
		tmp_a = tmp_a->next;
		// ps_env->stack_a = ps_env->stack_a->next;
	}
	printf("- -\n");
	printf("a b\n");
	// while (tmp)
	//{
	//	printf("stack-prev(%d) : %d\n", i--, tmp->data);
	//	tmp = tmp->prev;
	//}
}

int		main(int argc, char **argv)
{
	t_ps_env	*ps_env;

	if (!(ps_env = init_checker(argc, argv)))
		return (-1);
	start_checker(ps_env);
}
