/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fields_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 03:16:59 by luguimar          #+#    #+#             */
/*   Updated: 2023/12/21 18:49:36 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	set_values(t_list **stack_a, t_list **stack_b)
{
	set_index(stack_a, stack_b);
	set_inverse_index(stack_a, stack_b);
	set_half(stack_a, stack_b);
	set_price(stack_a, stack_b);
}

void	set_inverse_index(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = ft_lstsize(*stack_a) - 1;
	while (tmp)
	{
		((t_node *)tmp->content)->inverted_index = i;
		tmp = tmp->next;
		i--;
	}
	tmp = *stack_b;
	i = ft_lstsize(*stack_b) - 1;
	while (tmp)
	{
		((t_node *)tmp->content)->inverted_index = i;
		tmp = tmp->next;
		i--;
	}
}
