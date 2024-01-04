/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations_extra_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:11:55 by luguimar          #+#    #+#             */
/*   Updated: 2024/01/03 19:43:25 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	exec_cheapest_aux1(t_list **stack_a, t_list **stack_b, t_node *node)
{
	if (node->half == 0 && target_half(*stack_a, node->final_a_index) == 1 \
			&& node->index != 0 && bigger(node->index, target_index \
			(*stack_a, node->final_a_index)) < bigger(node-> \
			inverted_index, target_inverse_index(*stack_a, node-> \
			final_a_index) + 1) && bigger(node->index, target_index \
			(*stack_a, node->final_a_index)) < node->index + \
			target_inverse_index(*stack_a, node->final_a_index) + 1)
	{
		exec_operation(stack_a, stack_b, "rr");
		return (1);
	}
	else if (node->half == 0 && target_half(*stack_a, node->final_a_index) == 1 \
			&& node->index != 0 && bigger(node->inverted_index, \
			target_inverse_index(*stack_a, node->final_a_index)) + 1 \
			< bigger(node->index, target_index(*stack_a, node-> \
			final_a_index)) && bigger(node->inverted_index, \
			target_inverse_index(*stack_a, node->final_a_index)) + 1 \
			< node->index + target_inverse_index(*stack_a, \
			node->final_a_index) + 1)
	{
		exec_operation(stack_a, stack_b, "rrr");
		return (1);
	}
	return (0);
}

int	exec_cheapest_aux2(t_list **stack_a, t_list **stack_b, t_node *node)
{
	if (node->half == 0 && target_half(*stack_a, node->final_a_index) == 1 \
			&& node->index != 0 && node->index + target_inverse_index \
			(*stack_a, node->final_a_index) + 1 < bigger \
			(node->inverted_index, target_inverse_index(*stack_a, \
			node->final_a_index)) + 1 && bigger(node->index, target_index \
			(*stack_a, node->final_a_index)) > node->index \
			+ target_inverse_index(*stack_a, node->final_a_index) + 1)
	{
		exec_operation(stack_a, stack_b, "rb");
		return (1);
	}
	else if (node->half == 1 && target_half(*stack_a, node->final_a_index) == 0 \
			&& target_index(*stack_a, node->final_a_index) != 0 \
			&& node->inverted_index + target_index(*stack_a, node-> \
			final_a_index) + 1 < bigger(node->inverted_index, \
			target_inverse_index(*stack_a, node->final_a_index)) \
			+ 1 && bigger(node->index, target_index(*stack_a, node \
			->final_a_index)) > node->index + target_inverse_index \
			(*stack_a, node->final_a_index) + 1)
	{
		exec_operation(stack_a, stack_b, "ra");
		return (1);
	}
	return (0);
}

int	exec_cheapest_aux3(t_list **stack_a, t_list **stack_b, t_node *node)
{
	if (node->half == 1 && target_half(*stack_a, node->final_a_index) == 0 \
			&& target_index(*stack_a, node->final_a_index) != 0 \
			&& node->inverted_index + target_index(*stack_a, node-> \
			final_a_index) + 1 > bigger(node->inverted_index, \
			target_inverse_index(*stack_a, node->final_a_index)) \
			+ 1 && bigger(node->index, target_index(*stack_a, node \
			->final_a_index)) > bigger(node->inverted_index, \
			target_inverse_index(*stack_a, node->final_a_index)) + 1)
	{
		exec_operation(stack_a, stack_b, "rrr");
		return (1);
	}
	else if (node->half == 1 && target_half(*stack_a, node->final_a_index) == 0 \
			&& target_index(*stack_a, node->final_a_index) != 0 \
			&& node->inverted_index + target_index(*stack_a, node-> \
			final_a_index) + 1 > bigger(node->index, \
			target_index(*stack_a, node->final_a_index)) \
			&& bigger(node->index, target_index(*stack_a, node \
			->final_a_index)) < bigger(node->inverted_index, \
			target_inverse_index(*stack_a, node->final_a_index)) + 1)
	{
		exec_operation(stack_a, stack_b, "rr");
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
