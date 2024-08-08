/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddaniel- <ddaniel-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:24:51 by ddaniel-          #+#    #+#             */
/*   Updated: 2024/08/08 20:54:08 by ddaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

//push top node of b to a
void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

//push top node of a to b
void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
