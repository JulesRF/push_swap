/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:10:17 by jroux-fo          #+#    #+#             */
/*   Updated: 2022/03/19 19:31:31 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_spe_52(t_list *temp_a, t_list *temp_b)
{
	ft_reverse_rotate(&temp_a, 'a');
	ft_push(&temp_a, &temp_b, 'a');
	ft_reverse_rotate(&temp_a, 'a');
	ft_push(&temp_a, &temp_b, 'a');
	ft_sort_3(temp_a, temp_b);
	ft_push(&temp_b, &temp_a, 'b');
	ft_push(&temp_b, &temp_a, 'b');
}

int	ft_spe_5(t_list **list_a, t_list **list_b, int size)
{
	t_list	*la;
	t_list	*lb;

	(void)size;
	la = *list_a;
	lb = *list_b;
	if (la->index == 4 && la->next->index == 3 && la->next->next->index == 2
		&& la->next->next->next->index == 1
		&& la->next->next->next->next->index == 0)
		ft_spe_52(la, lb);
	else if (la->index == 2 && la->next->index == 4
		&& la->next->next->index == 3 && la->next->next->next->index == 1
		&& la->next->next->next->next->index == 0)
		ft_spe_52(la, lb);
	else if (la->index == 3 && la->next->index == 4
		&& la->next->next->index == 2 && la->next->next->next->index == 1
		&& la->next->next->next->next->index == 0)
		ft_spe_52(la, lb);
	else
		return (0);
	return (1);
}

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
