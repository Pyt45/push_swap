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

int		back(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return stack->data;
}