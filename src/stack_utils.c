#include "../include/push_swap.h"

t_stack     *create_stack(int data)
{
    t_stack     *stack;

    if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
        return (NULL);
    stack->data = data;
    stack->next = NULL;
    stack->prev = NULL;
    return (stack);
}

void	push_back(t_stack **root, int data)
{
	t_stack *tmp;
	t_stack	*new;

	tmp = *root;
	new = create_stack(data);
	if (!(*root))
	{
		(*root) = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}
// |1| --> |2| --> |3|
void	push_front(t_stack **root, int data)
{
	t_stack *new;

	new = create_stack(data);
	if (!(*root))
	{
		(*root) = new;
		return ;
	}
	new->next = (*root);
	(*root)->prev = new;
	(*root) = new;
}

t_stack		*getStack(t_stack **root, int data)
{
	t_stack		*stack;

	stack = *root;
	while (stack)
	{
		if (stack->data == data)
			return stack;
		stack = stack->next;
	}
	return (NULL);
}

t_stack		*getStackPos(t_stack **root, int pos)
{
	t_stack		*tmp;

	tmp = *root;
	while (tmp && pos)
	{
		pos--;
		tmp = tmp->next;
	}
	return tmp;
}

int		back(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return stack->data;
}

int 	get_stack_len(t_ps_env *ps_env, char stack_name)
{
	int 	len;
	t_stack *iter;

	len = 0;

	iter = (stack_name == 'a') ? ps_env->stack_a : ps_env->stack_b;
	while (iter)
	{
		len++;
		iter = iter->next;
	}
	return (len);
}