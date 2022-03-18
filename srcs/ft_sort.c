/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:42:02 by jroux-fo          #+#    #+#             */
/*   Updated: 2022/03/18 15:44:06 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_list *list_a, t_list *list_b)
{
	(void)list_b;
	if (list_a->value > list_a->next->value && list_a->next->value < list_a
		->next->next->value && list_a->value < list_a->next->next->value)
		ft_swap(list_a, 'a');
	if (list_a->value > list_a->next->value && list_a->next->value < list_a
		->next->next->value && list_a->value > list_a->next->next->value)
		ft_rotate(list_a, 'a');
	if (list_a->value > list_a->next->value && list_a->next->value > list_a
		->next->next->value && list_a->value > list_a->next->next->value)
	{
		ft_rotate(list_a, 'a');
		ft_swap(list_a, 'a');
	}
	if (list_a->value < list_a->next->value && list_a->next->value > list_a
		->next->next->value && list_a->value < list_a->next->next->value)
	{
		ft_swap(list_a, 'a');
		ft_rotate(list_a, 'a');
	}
	if (list_a->value < list_a->next->value && list_a->next->value > list_a
		->next->next->value && list_a->value > list_a->next->next->value)
	{
		ft_rotate(list_a, 'a');
		ft_rotate(list_a, 'a');
	}
}

int	ft_smallest(t_list *list)
{
	int	nb;

	nb = list->value;
	while (list)
	{
		if (list->value < nb)
			nb = list->value;
		list = list->next;
	}
	return (nb);
}

void	ft_small_sort(t_list **list_a, t_list **list_b, int size)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = *list_a;
	temp_b = *list_b;
	while (ft_lstsize(temp_a) > 3)
	{
		while (ft_smallest(temp_a) != temp_a->value)
			ft_rotate(temp_a, 'a');
		ft_push(&temp_a, &temp_b, 'a');
	}
	ft_sort_3(temp_a, temp_b);
	ft_push(&temp_b, &temp_a, 'b');
	if (size == 5)
		ft_push(&temp_b, &temp_a, 'b');
}

void	ft_big_sort(t_list **list_a, t_list **list_b, int size)
{
	int		i;
	int		j;
	int		nb;

	i = 0;
	while (ft_is_sorted2(*list_a) != 0)
	{
		j = 0;
		while (j < size)
		{
			nb = (*list_a)->index;
			if ((nb >> i) & 1)
				ft_rotate(*list_a, 'a');
			else
				ft_push(list_a, list_b, 'a');
			j++;
		}
		nb = size - ft_lstsize(*list_a);
		j = 0;
		while (j++ < nb)
			ft_push(list_b, list_a, 'b');
		i++;
		*list_b = NULL;
	}
}

void	ft_sort(t_list **list_a, t_list **list_b)
{
	if (ft_lstsize(*list_a) == 2)
		ft_rotate(*list_a, 'a');
	else if (ft_lstsize(*list_a) == 3)
		ft_sort_3(*list_a, *list_b);
	else if (ft_lstsize(*list_a) <= 5)
		ft_small_sort(list_a, list_b, ft_lstsize(*list_a));
	else
		ft_big_sort(list_a, list_b, ft_lstsize(*list_a));
}
