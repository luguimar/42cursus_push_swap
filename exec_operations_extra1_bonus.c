/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations_extra1_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:35:39 by luguimar          #+#    #+#             */
/*   Updated: 2023/12/26 21:28:20 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	exec_cheapest_aux6(t_list **stack_a, t_list **stack_b, t_node *node)
{
	if (node->half != 0 && target_half(*stack_a,
			node->final_a_index) == 0 && target_index(*stack_a,
			node->final_a_index) == 0)
	{
		exec_operation(stack_a, stack_b, "rrb");
		return (1);
	}
	else if (node->half != 0 && target_half(*stack_a,
			node->final_a_index) == 0 && target_index(*stack_a,
			node->final_a_index) != 0)
	{
		exec_operation(stack_a, stack_b, "ra");
		exec_operation(stack_a, stack_b, "rrb");
		return (1);
	}
	else if (node->half != 0 && target_index(*stack_a,
			node->final_a_index) == 0)
	{
		exec_operation(stack_a, stack_b, "rrb");
		return (1);
	}
	return (0);
}

int	exec_cheapest_aux7(t_list **stack_a, t_list **stack_b, t_node *node)
{
	if (node->half != 0 && target_half(*stack_a,
			node->final_a_index) == 0 && target_index(*stack_a,
			node->final_a_index) != 0)
	{
		exec_operation(stack_a, stack_b, "ra");
		exec_operation(stack_a, stack_b, "rrb");
		return (1);
	}
	else if (node->half != 0 && target_half(*stack_a,
			node->final_a_index) != 0)
	{
		exec_operation(stack_a, stack_b, "rrr");
		return (1);
	}
	return (0);
}
