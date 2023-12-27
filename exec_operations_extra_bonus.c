/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations_extra_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:11:55 by luguimar          #+#    #+#             */
/*   Updated: 2023/12/26 21:26:51 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	exec_cheapest_aux1(t_list **stack_a, t_list **stack_b, t_node *node)
{
	if (node->value > ((t_node *)biggest(*stack_a)->content)->value
		&& node->half == ((t_node *)smallest(*stack_a)->content)->half
		&& node->half == 1)
	{
		exec_operation(stack_a, stack_b, "rrr");
		return (1);
	}
	else if (node->value > ((t_node *)biggest(*stack_a)->content)->value
		&& node->half == ((t_node *)smallest(*stack_a)->content)->half
		&& node->half == 0 && node->index != 0
		&& ((t_node *)smallest(*stack_a)->content)->index != 0)
	{
		exec_operation(stack_a, stack_b, "rr");
		return (1);
	}
	else if (node->value > ((t_node *)biggest(*stack_a)->content)->value
		&& node->half != ((t_node *)smallest(*stack_a)->content)->half
		&& node->half == 0 && node->index == 0)
	{
		exec_operation(stack_a, stack_b, "rra");
		return (1);
	}
	return (0);
}

int	exec_cheapest_aux2(t_list **stack_a, t_list **stack_b, t_node *node)
{
	if (node->value > ((t_node *)biggest(*stack_a)->content)->value
		&& node->half != ((t_node *)smallest(*stack_a)->content)->half
		&& node->half == 1
		&& ((t_node *)smallest(*stack_a)->content)->index == 0)
	{
		exec_operation(stack_a, stack_b, "rrb");
	}
	else if (node->value > ((t_node *)biggest(*stack_a)->content)->value
		&& node->half != ((t_node *)smallest(*stack_a)->content)->half
		&& node->half == 1
		&& ((t_node *)smallest(*stack_a)->content)->index != 0)
	{
		exec_operation(stack_a, stack_b, "ra");
		exec_operation(stack_a, stack_b, "rrb");
		return (1);
	}
	else if (node->value > ((t_node *)biggest(*stack_a)->content)->value
		&& node->half != ((t_node *)smallest(*stack_a)->content)->half
		&& node->half == 1
		&& ((t_node *)smallest(*stack_a)->content)->index == 0)
	{
		exec_operation(stack_a, stack_b, "rb");
		return (1);
	}
	return (0);
}

int	exec_cheapest_aux3(t_list **stack_a, t_list **stack_b, t_node *node)
{
	if (node->value > ((t_node *)biggest(*stack_a)->content)->value
		&& node->half == ((t_node *)smallest(*stack_a)->content)->half
		&& node->half == 0 && node->index == 0
		&& ((t_node *)smallest(*stack_a)->content)->index != 0)
	{
		exec_operation(stack_a, stack_b, "ra");
		return (1);
	}
	else if (node->value > ((t_node *)biggest(*stack_a)->content)->value
		&& node->half != ((t_node *)smallest(*stack_a)->content)->half
		&& node->half == 0 && node->index != 0)
	{
		exec_operation(stack_a, stack_b, "rb");
		exec_operation(stack_a, stack_b, "rra");
		return (1);
	}
	else if (node->value > ((t_node *)biggest(*stack_a)->content)->value
		&& node->half == ((t_node *)smallest(*stack_a)->content)->half
		&& node->index == 0
		&& ((t_node *)smallest(*stack_a)->content)->index == 0)
	{
		exec_operation(stack_a, stack_b, "pa");
		return (1);
	}
	return (0);
}

int	exec_cheapest_aux4(t_list **stack_a, t_list **stack_b, t_node *node)
{
	if (node->index == 0 && target_index(*stack_a,
			node->final_a_index) == 0)
	{
		exec_operation(stack_a, stack_b, "pa");
		return (1);
	}
	else if (target_half(*stack_a, node->final_a_index) == 0
		&& node->index == 0 && target_index(*stack_a,
			node->final_a_index) != 0)
	{
		exec_operation(stack_a, stack_b, "ra");
		return (1);
	}
	else if (node->half == 0 && node->index != 0
		&& target_index(*stack_a, node->final_a_index) == 0)
	{
		exec_operation(stack_a, stack_b, "rb");
		return (1);
	}
	return (0);
}

int	exec_cheapest_aux5(t_list **stack_a, t_list **stack_b, t_node *node)
{
	if (node->half == 0 && target_half(*stack_a,
			node->final_a_index) == 0 && node->index != 0
		&& target_index(*stack_a, node->final_a_index) != 0)
	{
		exec_operation(stack_a, stack_b, "rr");
		return (1);
	}
	else if (node->half == 0 && target_half(*stack_a,
			node->final_a_index) != 0 && node->index == 0)
	{
		exec_operation(stack_a, stack_b, "rra");
		return (1);
	}
	else if (node->half == 0 && target_half(*stack_a,
			node->final_a_index) != 0 && node->index != 0)
	{
		exec_operation(stack_a, stack_b, "rb");
		exec_operation(stack_a, stack_b, "rra");
		return (1);
	}
	return (0);
}
