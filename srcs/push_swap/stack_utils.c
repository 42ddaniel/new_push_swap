/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddaniel- <ddaniel-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:56:29 by ddaniel-          #+#    #+#             */
/*   Updated: 2024/06/23 18:21:06 by ddaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_lstsize(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack -> next;
		count++;
	}
	return (count);
}

t_stack_node	*ft_lstlast(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack -> next)
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_smallest(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*smallest_node;

	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < smallest)
		{
			smallest = stack->nbr;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack_node	*find_bigger(t_stack_node *stack)
{
	long			big;
	t_stack_node	*bigger_node;

	if (!stack)
		return (NULL);
	big = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > big)
		{
			big = stack->nbr;
			bigger_node = stack;
		}
		stack = stack->next;
	}
	return (bigger_node);
}
