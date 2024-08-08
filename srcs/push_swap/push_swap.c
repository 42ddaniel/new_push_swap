/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddaniel- <ddaniel-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:58:02 by ddaniel-          #+#    #+#             */
/*   Updated: 2024/06/24 20:37:57 by ddaniel-         ###   ########.fr       */
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
	char			**new_argv;

	a = NULL;
	b = NULL;
	new_argv = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		new_argv = ft_split(argv[1], ' ');
		init_stack_a(&a, new_argv);
	}
	else
		init_stack_a(&a, (argv + 1));
	if (!stack_sorted(a))
		manage_stacks(&a, &b);
	free_stack(&a);
	if (new_argv)
		free_av(new_argv);
	return (0);
}
