/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddaniel- <ddaniel-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:24:57 by ddaniel-          #+#    #+#             */
/*   Updated: 2024/06/24 19:52:18 by ddaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate_both(t_stack_node **a,
	t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack_node **a,
	t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	move_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(*a);
	if (!cheapest_node)
		return ;
	if (cheapest_node->above_mid
		&& cheapest_node->target_node->above_mid)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_mid)
		&& !(cheapest_node->target_node->above_mid))
		rev_rotate_both(a, b, cheapest_node);
	prep_to_push(a, cheapest_node, 'a');
	prep_to_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

static void	move_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_to_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_a(*a, *b);
		move_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_b(*a, *b);
		move_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
