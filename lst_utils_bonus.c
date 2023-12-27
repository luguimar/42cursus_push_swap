/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:27:08 by luguimar          #+#    #+#             */
/*   Updated: 2023/12/21 19:02:09 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*biggest(t_list *stack)
{
	t_list	*tmp;
	t_list	*biggest;
	t_node	*node;

	tmp = stack;
	biggest = tmp;
	node = (t_node *)tmp->content;
	while (tmp)
	{
		if (node->value > ((t_node *)biggest->content)->value)
			biggest = tmp;
		tmp = tmp->next;
		if (tmp)
			node = (t_node *)tmp->content;
	}
	return (biggest);
}

t_list	*smallest(t_list *stack)
{
	t_list	*tmp;
	t_list	*smlst;
	t_node	*node;

	tmp = stack;
	smlst = tmp;
	node = (t_node *)tmp->content;
	while (tmp)
	{
		if (node->value < ((t_node *)smlst->content)->value)
			smlst = tmp;
		tmp = tmp->next;
		if (tmp)
			node = (t_node *)tmp->content;
	}
	return (smlst);
}

int	sort_organized_price(t_list *stack)
{
	int	price;

	if (((t_node *)smallest(stack)->content)->half == 0)
		price = ((t_node *)smallest(stack)->content)->index;
	else
		price = ((t_node *)smallest(stack)->content)->inverted_index + 1;
	return (price);
}

void	sort_organized(t_list **stack_a)
{
	int		smlst_half;
	t_list	*smlst;
	t_list	*tmp;

	tmp = *stack_a;
	smlst = smallest(*stack_a);
	if (is_organized(tmp, ((t_node *)smlst->content)->final_a_index,
			((t_node *)smlst->content)->index))
	{
		smlst_half = ((t_node *)smlst->content)->half;
		if (smlst_half == 0)
		{
			while (((t_node *)smlst->content)->index != 0)
				exec_operation(stack_a, NULL, "ra");
		}
		else
		{
			while (((t_node *)smlst->content)->index != 0)
				exec_operation(stack_a, NULL, "rra");
		}
	}
}

void	wrong_args(t_list *a, t_list *b, char *line)
{
	ft_putstr_fd("Error\n", 2);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	free(line);
	exit(1);
}
/*
static t_node	*lstdup_node(t_node *content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = content->value;
	node->index = content->index;
	node->final_a_index = content->final_a_index;
	return (node);
}

t_list	*lstdup(t_list *lst)
{
	t_list	*tmp;

	tmp = ft_lstnew(lstdup_node(lst->content));
	if (!tmp)
		return (NULL);
	return (tmp);
}*/
