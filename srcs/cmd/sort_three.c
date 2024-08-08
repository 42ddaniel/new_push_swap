/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddaniel- <ddaniel-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:25:03 by ddaniel-          #+#    #+#             */
/*   Updated: 2024/06/24 00:20:22 by ddaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_bigger(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}
