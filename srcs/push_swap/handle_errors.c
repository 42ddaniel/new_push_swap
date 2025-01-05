/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddaniel- <ddaniel-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:43:52 by ddaniel-          #+#    #+#             */
/*   Updated: 2025/01/05 23:16:21 by ddaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	error_syntax(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free (current);
		current = tmp;
	}
	free(current);
	*stack = NULL;
}

void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (!argv || !*argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	free_errors(t_stack_node **a, char **argv, bool argc_is_2)
{
	free_stack(a);
	if (argc_is_2)
		free_matrix(argv);
	write(1, "Error\n", 6);
	exit(1);
}

void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_smallest(*a)->nbr)
	{
		if (find_smallest(*a)->above_mid)
			ra(a);
		else
			rra(a);
	}
}
