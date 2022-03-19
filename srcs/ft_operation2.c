/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:10:17 by jroux-fo          #+#    #+#             */
/*   Updated: 2022/03/19 18:21:30 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sswap(t_list *list_a, t_list *list_b)
{
	ft_swap(list_a, 'a');
	ft_swap(list_b, 'b');
}

void	ft_rrotate(t_list *list_a, t_list *list_b)
{
	ft_rotate(list_a, 'a');
	ft_rotate(list_b, 'b');
}

void	ft_rreverse_rotate(t_list **list_a, t_list **list_b)
{
	ft_reverse_rotate(list_a, 'a');
	ft_reverse_rotate(list_b, 'b');
}
