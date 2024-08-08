/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddaniel- <ddaniel-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:50:05 by ddaniel-          #+#    #+#             */
/*   Updated: 2024/08/08 20:54:31 by ddaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//rotate the bottom node to the top
void	r_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!stack || !(*stack)->next)
		return ;
	last_node = ft_lstlast(*stack);
	(*stack)->prev = last_node;
	last_node->prev->next = NULL;
	last_node->next = (*stack);
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a)
{
	r_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	r_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	r_rotate(a);
	r_rotate(b);
	write(1, "rrr\n", 4);
}
