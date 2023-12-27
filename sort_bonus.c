/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:37:13 by luguimar          #+#    #+#             */
/*   Updated: 2023/12/21 18:55:07 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sort_three(t_list **stack_a)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;

	node1 = (t_node *)(*stack_a)->content;
	node2 = (t_node *)(*stack_a)->next->content;
	node3 = (t_node *)(*stack_a)->next->next->content;
	if (node2->value > node3->value && node2->value > node1->value)
		exec_operation(stack_a, NULL, "rra");
	else if (node1->value > node2->value && node1->value > node3->value)
		exec_operation(stack_a, NULL, "ra");
	else
		exec_operation(stack_a, NULL, "sa");
}

void	sort_four_and_five(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		exec_operation(stack_a, stack_b, "pb");
		set_values(stack_a, stack_b);
	}
	while (!is_sorted(*stack_a))
	{
		sort_three(stack_a);
		set_values(stack_a, stack_b);
	}
	while (ft_lstsize(*stack_b))
	{
		exec_cheapest(stack_a, stack_b);
		set_values(stack_a, stack_b);
	}
	sort_four_and_five_extra(stack_a, stack_b);
}

void	sort_many(t_list **stack_a, t_list **stack_b)
{
	int	median;
	int	original_size;

	median = set_median(*stack_a);
	original_size = ft_lstsize(*stack_a);
	while (ft_lstsize(*stack_a) > 3)
	{
		while (((t_node *)(*stack_a)->content)->value > median &&
				ft_lstsize(*stack_a) > original_size / 2)
			exec_operation(stack_a, stack_b, "ra");
		exec_operation(stack_a, stack_b, "pb");
	}
	set_values(stack_a, stack_b);
	while (!is_sorted(*stack_a))
	{
		sort_three(stack_a);
		set_values(stack_a, stack_b);
	}
	while (ft_lstsize(*stack_b))
	{
		exec_cheapest(stack_a, stack_b);
		set_values(stack_a, stack_b);
	}
	sort_many_extra(stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	while (!is_sorted(*stack_a) || ft_lstsize(*stack_b) > 0)
	{
		if (ft_lstsize(*stack_a) == 2)
			exec_operation(stack_a, stack_b, "sa");
		else if (ft_lstsize(*stack_a) == 3 && ft_lstsize(*stack_b) == 0)
			sort_three(stack_a);
		else if (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_a) < 6
			&& ft_lstsize(*stack_b) == 0)
			sort_four_and_five(stack_a, stack_b);
		else
			sort_many(stack_a, stack_b);
		set_values(stack_a, stack_b);
	}
}
