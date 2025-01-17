/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddaniel- <ddaniel-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:58:02 by ddaniel-          #+#    #+#             */
/*   Updated: 2025/01/17 13:14:57 by ddaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	manage_stacks(t_stack_node **a, t_stack_node **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else
		sort_stacks(a, b);
}

void	free_av(char **new_argv)
{
	int	i;

	i = 0;
	if (!new_argv)
		return ;
	while (new_argv[i])
		free(new_argv[i++]);
	free(new_argv);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, (argv + 1), (argc == 2));
	if (!stack_sorted(a))
		manage_stacks(&a, &b);
	free_stack(&a);
	return (0);
}
