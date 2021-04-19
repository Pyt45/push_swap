/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:11:11 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/19 22:17:08 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_inst	*create_inst(char *op)
{
	t_inst	*new;

	new = (t_inst *)malloc(sizeof(t_inst));
	if (new)
	{
		new->op = strdup(op);
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

void	push_back_inst(t_inst **root, char *op)
{
	t_inst	*new;

	new = create_inst(op);
	if (!(*root))
	{
		*root = new;
		return ;
	}
	while((*root)->next)
		(*root) = (*root)->next;
	(*root)->next = new;
	new->prev = *root;
}

void	push_swap(t_ps_env *ps_env)
{
	t_stack		*iter;
	t_stack		*test;
	int			len_a;

	iter = ps_env->stack_a;
	len_a = get_stack_len(ps_env, 'a');
	printf("%d\n", len_a);
	test = getStackPos(&ps_env->stack_a, 2);
	printf("data = %d\n", test->data);
	while (iter)
	{
		printf("%d\n", iter->data);
		iter = iter->next;
	}
}