/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:11:11 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/18 16:21:35 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_ps_env *ps_env)
{
	t_stack		*iter;
	int			len_a;

	iter = ps_env->stack_a;
	len_a = get_stack_len(ps_env, 'a');
	printf("%d\n", len_a);
	while (iter)
	{
		printf("%d\n", iter->data);
		iter = iter->next;
	}
}