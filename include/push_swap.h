/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddaniel- <ddaniel-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:49:29 by ddaniel-          #+#    #+#             */
/*   Updated: 2025/01/17 11:50:09 by ddaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_mid;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//ERRORS
int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a, char **argv, bool argc_is_2);
void			free_av(char **new_argv);
void			free_matrix(char **argv);

//STACK INIT
void			init_stack_a(t_stack_node **a, char **argv, bool argc_is_2);
char			**ft_split(char *s, char c);

//NODES
t_stack_node	*return_cheapest(t_stack_node *stack);
void			init_a(t_stack_node *a, t_stack_node *b);
void			init_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			prep_to_push(t_stack_node **stack,
					t_stack_node *top_node, char stack_name);

//STACK UTILS
int				ft_lstsize(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*ft_lstlast(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*find_bigger(t_stack_node *stack);

//COMMANDS
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

//ALGORITHMS
void			sort_three(t_stack_node **a);
void			min_on_top(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);

#endif
