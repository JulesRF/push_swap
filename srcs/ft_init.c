/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:17:13 by jroux-fo          #+#    #+#             */
/*   Updated: 2022/03/18 15:16:19 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_is_sorted(t_list **list, t_list *temp)
{
	if (temp->next == NULL)
		ft_exit(list, "", 0);
	if (temp->next->next == NULL)
	{
		if (temp->value <= temp->next->value)
			ft_exit(list, "", 0);
		return ;
	}
	while (temp->next->next)
	{
		if (temp->next->value < temp->value)
			return ;
		temp = temp->next;
	}
	if (temp->next->value < temp->value)
		return ;
	ft_exit(list, "", 0);
}

int	ft_is_sorted2(t_list *list)
{
	while (list->next->next)
	{
		if (list->next->value < list->value)
			return (1);
		list = list->next;
	}
	if (list->next->value < list->value)
		return (1);
	return (0);
}

void	ft_init_list(t_list **list, int argc, char **argv)
{
	char	**dest;
	int		i;

	i = 1;
	if (argc == 1)
	{
		dest = ft_split(argv[1], ' ');
		*list = ft_lstnew(ft_atoi(dest[0], dest, 0));
		while (dest[i] != 0)
		{
			ft_lstadd_back(list, ft_lstnew(ft_atoi(dest[i], dest, 0)));
			i++;
		}
		ft_free_split(dest);
		return ;
	}
	i++;
	*list = ft_lstnew(ft_atoi(argv[1], argv, 0));
	while (argv[i])
	{
		ft_lstadd_back(list, ft_lstnew(ft_atoi(argv[i], argv, 0)));
		i++;
	}
}
