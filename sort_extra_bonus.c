/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_extra_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:28:16 by luguimar          #+#    #+#             */
/*   Updated: 2023/12/21 18:55:19 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sort_four_and_five_extra(t_list **stack_a, t_list **stack_b)
{
	if (is_organized(*stack_a,
			((t_node *)biggest(*stack_a)->content)->final_a_index,
			((t_node *)biggest(*stack_a)->content)->index))
	{
		while (((t_node *)smallest(*stack_a)->content)->index > \
				ft_lstsize(*stack_a)
			/ 2)
		{
			exec_operation(stack_a, NULL, "rra");
			set_values(stack_a, stack_b);
		}
		while (((t_node *)smallest(*stack_a)->content)->index != 0)
		{
			exec_operation(stack_a, NULL, "ra");
			set_values(stack_a, stack_b);
		}
	}
}

void	sort_many_extra(t_list **stack_a, t_list **stack_b)
{
	if (is_organized(*stack_a,
			((t_node *)biggest(*stack_a)->content)->final_a_index,
			((t_node *)biggest(*stack_a)->content)->index))
	{
		while (((t_node *)smallest(*stack_a)->content)->index > \
				ft_lstsize(*stack_a)
			/ 2)
		{
			exec_operation(stack_a, NULL, "rra");
			set_values(stack_a, stack_b);
		}
		while (((t_node *)smallest(*stack_a)->content)->index != 0)
		{
			exec_operation(stack_a, NULL, "ra");
			set_values(stack_a, stack_b);
		}
	}
}
