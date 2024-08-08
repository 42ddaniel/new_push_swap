/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddaniel- <ddaniel-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:25:00 by ddaniel-          #+#    #+#             */
/*   Updated: 2024/08/08 20:54:45 by ddaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// Swap the first and second nodes
static void	swap(t_stack_node **top)
{
	if (!*top || !(*top)->next)
		return ;
	*top = (*top)->next;
	(*top)->prev->prev = *top;
	(*top)->prev->next = (*top)->next;
	if ((*top)->next)
		(*top)->next->prev = (*top)->prev;
	(*top)->next = (*top)->prev;
	(*top)->prev = NULL;
}

void	sa(t_stack_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
