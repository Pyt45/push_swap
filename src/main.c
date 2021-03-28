#include "../include/push_swap.h"

void	print_stack_a(t_ps_env *ps_env)
{
	t_stack *tmp = ps_env->stack_a;

	printf("Init a and b:\n");
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
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
