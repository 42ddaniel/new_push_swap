/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddaniel- <ddaniel-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:29:48 by ddaniel-          #+#    #+#             */
/*   Updated: 2024/08/08 20:54:20 by ddaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//rotate the top node to the bottom
static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	t_stack_node	*old_first;

	if (!*stack || !stack || !(*stack)->next)
		return ;
	old_first = (*stack);
	last_node = ft_lstlast(*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next = old_first;
	old_first->prev = last_node;
	old_first->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
