/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculators_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:59:11 by luguimar          #+#    #+#             */
/*   Updated: 2023/12/21 18:59:53 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	lowest_price_index(t_list *stack_b)
{
	t_list	*tmp;
	int		lowest_price;
	int		lowest_price_index;
	int		lowest_price_final_index;

	tmp = stack_b;
	lowest_price = -1;
	lowest_price_index = ((t_node *)tmp->content)->index;
	lowest_price_final_index = ((t_node *)tmp->content)->final_a_index;
	while (tmp)
	{
		if (((t_node *)tmp->content)->price < lowest_price || lowest_price == -1
			|| (((t_node *)tmp->content)->price == lowest_price
				&& ((t_node *)tmp->content)->final_a_index
				< lowest_price_final_index))
		{
			lowest_price = ((t_node *)tmp->content)->price;
			lowest_price_index = ((t_node *)tmp->content)->index;
			lowest_price_final_index = ((t_node *)tmp->content)->final_a_index;
		}
		tmp = tmp->next;
	}
	return (lowest_price_index);
}

int	set_median(t_list *stack_a)
{
	t_list	*tmp;
	t_node	*node;

	tmp = stack_a;
	node = (t_node *)tmp->content;
	while (tmp)
	{
		if (node->final_a_index == ft_lstsize(stack_a) / 2)
			return (node->value);
		if (tmp->next)
			tmp = tmp->next;
		node = (t_node *)tmp->content;
	}
	return (node->value);
}

int	target_half(t_list *stack_a, int src_final_index)
{
	int	target_half;
	int	targt_index;

	targt_index = target_index(stack_a, src_final_index);
	if (targt_index < ft_lstsize(stack_a) / 2)
		target_half = 0;
	else
		target_half = 1;
	return (target_half);
}

int	target_inverse_index(t_list *stack_a, int src_final_index)
{
	int		target_inverse_index;
	int		targt_index;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack_a;
	targt_index = target_index(stack_a, src_final_index);
	while (i < targt_index)
	{
		tmp = tmp->next;
		i++;
	}
	target_inverse_index = ((t_node *)tmp->content)->inverted_index;
	return (target_inverse_index);
}

int	target_index(t_list *stack_a, int src_final_index)
{
	t_list	*tmp;
	int		smallest_bigger_index;
	int		smallest_bigger_final_index;

	tmp = stack_a;
	smallest_bigger_index = -1;
	smallest_bigger_final_index = -1;
	while (tmp)
	{
		if ((((t_node *)tmp->content)->final_a_index > src_final_index) && \
			(((t_node *)tmp->content)->final_a_index < \
			smallest_bigger_final_index
				|| smallest_bigger_index == -1))
		{
			smallest_bigger_final_index = ((t_node *)
					tmp->content)->final_a_index;
			smallest_bigger_index = ((t_node *)tmp->content)->index;
		}
		tmp = tmp->next;
	}
	return (smallest_bigger_index);
}
