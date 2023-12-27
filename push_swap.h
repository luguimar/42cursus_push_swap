/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:56:06 by luguimar          #+#    #+#             */
/*   Updated: 2023/12/26 21:20:19 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int	value;
	int	index;
	int	inverted_index;
	int	final_a_index;
	int	price;
	int	half;
}		t_node;

int		is_sorted(t_list *node);
void	wrong_args(void);
void	swap(t_list **stack);
void	push(t_list **stack_orig, t_list **stack_dest);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	operations_aux(t_list **stack_a, t_list **stack_b, char *line);
void	exec_operation(t_list **stack_a, t_list **stack_b, char *line);
void	sort(t_list **stack_a, t_list **stack_b);
void	set_index(t_list **stack_a, t_list **stack_b);
void	set_final_a_index(t_list **stack_a);
t_list	*lstdup(t_list *lst);
void	set_init_node_values(t_node *node, char **args, int i);
void	set_price(t_list **stack_a, t_list **stack_b);
int		target_index(t_list *stack_a, int src_final_index);
int		bigger(int a, int b);
int		smaller(int a, int b);
void	set_half(t_list **stack_a, t_list **stack_b);
int		target_half(t_list *stack_a, int src_final_index);
void	set_inverse_index(t_list **stack_a, t_list **stack_b);
int		target_inverse_index(t_list *stack_a, int src_final_index);
int		set_median(t_list *stack_a);
void	set_values(t_list **stack_a, t_list **stack_b);
int		lowest_price_index(t_list *stack_b);
void	exec_cheapest(t_list **stack_a, t_list **stack_b);
int		is_organized(t_list *node, int bigger_final_index,
			int bigger_final_index_index);
void	sort_organized(t_list **stack_a);
t_list	*smallest(t_list *stack);
t_list	*biggest(t_list *stack);
int		sort_organized_price(t_list *stack);
void	set_half_for_stack(t_list **stack);
void	sort_four_and_five_extra(t_list **stack_a, t_list **stack_b);
void	sort_many_extra(t_list **stack_a, t_list **stack_b);
void	set_price_extra(t_list **stack_a, t_node *node);
void	set_price_stack_a(t_list **stack_a);
int		exec_cheapest_aux1(t_list **stack_a, t_list **stack_b, t_node *node);
int		exec_cheapest_aux2(t_list **stack_a, t_list **stack_b, t_node *node);
int		exec_cheapest_aux3(t_list **stack_a, t_list **stack_b, t_node *node);
int		exec_cheapest_aux4(t_list **stack_a, t_list **stack_b, t_node *node);
int		exec_cheapest_aux5(t_list **stack_a, t_list **stack_b, t_node *node);
int		exec_cheapest_aux6(t_list **stack_a, t_list **stack_b, t_node *node);
int		exec_cheapest_aux7(t_list **stack_a, t_list **stack_b, t_node *node);
int		exec_cheapest_extra(t_list **stack_a, t_list **stack_b, t_node *node);

void	print_stack(t_list *node);
void	print_half(t_list *node);
void	print_inverse_index(t_list *node);
void	print_final_a_index(t_list *node);
void	print_prices(t_list *node);
void	print_index(t_list *node);

#endif
