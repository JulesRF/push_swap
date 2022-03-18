/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:13:02 by jroux-fo          #+#    #+#             */
/*   Updated: 2022/03/18 15:15:44 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

void	ft_free_split(char	**dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest[i]);
	free(dest);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*to_suppr;

	while (*lst)
	{
		to_suppr = *lst;
		*lst = to_suppr->next;
		free(to_suppr);
	}
	*lst = NULL;
}

void	ft_exit(t_list **list, char *text, int end)
{
	if (text)
		ft_putstr(text);
	ft_lstclear(list);
	exit(end);
}

long int	*ft_init_tab(long int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab[i] = 2147483648;
		i++;
	}
	return (tab);
}
