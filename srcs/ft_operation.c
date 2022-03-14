/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:47:34 by jroux-fo          #+#    #+#             */
/*   Updated: 2022/03/14 17:48:32 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *list, char wich)
{
	int	temp;

	if (list == NULL || list->next == NULL)
	{
		ft_putstr("Error\n");
		return ;
	}
	while (list->next->next)
		list = list->next;
	temp = list->value;
	list->value = list->next->value;
	list->next->value = temp;
	if (wich == 'a')
		ft_putstr("sa\n");
	else
		ft_putstr("sb\n");
}

void	ft_push(t_list **send, t_list **receive, char wich)
{
	t_list	*temp;

	temp = *send;
	if (temp == NULL)
	{
		ft_putstr("Error\n");
		return ;
	}
	*send = (*send)->next;
	temp->next = *(receive);
	*(receive) = temp;
	if (wich == 'a')
		ft_putstr("pa\n");
	else
		ft_putstr("pb\n");
}

void	ft_reverse_rotate(t_list **list)
{
	t_list	*temp;
	t_list	*last;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	temp = *list;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *list;
	(*list) = last;
}

void	ft_rotate(t_list *list, char wich)
{
	int	temp;
	int	indextemp;

	if (list == NULL || list->next == NULL)
		return ;
	temp = list->value;
	indextemp = list->index;
	while (list->next)
	{
		list->value = list->next->value;
		list->index = list->next->index;
		list = list->next;
	}
	list->value = temp;
	list->index = indextemp;
	if (wich == 'a')
		ft_putstr("ra\n");
	else
		ft_putstr("rb\n");
}
