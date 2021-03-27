#include "../include/push_swap.h"

void	printStack(t_stack *stack)
{
	t_stack *tmp;

	printf("Init a and b:\n");
	while (stack)
	{
		printf("%d\n", stack->data);
		tmp = stack;
		stack = stack->next;
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
