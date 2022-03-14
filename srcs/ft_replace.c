/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:45:14 by jroux-fo          #+#    #+#             */
/*   Updated: 2022/03/14 18:33:04 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_duplicate(long int *tab, int nb, int size)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (i < size)
	{
		if (tab[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

int	ft_mini(t_list **list, long int *tab, int size)
{
	t_list	*temp;
	int		nb;

	temp = *list;
	nb = temp->value;
	while (temp)
	{
		if (temp->value == nb && ft_duplicate(tab, temp->value, size) == 1)
			nb = temp->next->value;
		if (temp->value < nb && ft_duplicate(tab, temp->value, size) == 0)
			nb = temp->value;
		temp = temp->next;
	}
	return (nb);
}

void	ft_replace3(t_list **list, long int *src, int *dest, int size)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *list;
	while (i < size)
	{
		temp->index = dest[i];
		i++;
		temp = temp->next;
	}
	free(dest);
	free(src);
}

void	ft_replace2(t_list **list, long int *src, int size)
{
	int		i;
	int		j;
	t_list	*temp;
	int		*dest;

	temp = *list;
	dest = malloc(sizeof(int) * size);
	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (temp->value == src[j])
				dest[i] = j;
			j++;
		}
		i++;
		temp = temp->next;
	}
	ft_replace3(list, src, dest, size);
}

void	ft_replace(t_list **list_a)
{
	t_list		*temp_a;
	long int	*tab;
	int			i;
	int			size;

	i = 1;
	temp_a = *list_a;
	size = ft_lstsize(temp_a);
	tab = malloc(sizeof(long int) * size);
	tab = ft_init_tab(tab, size);
	tab[0] = ft_mini(&temp_a, tab, size);
	while (i < size)
	{
		tab[i] = ft_mini(&temp_a, tab, size);
		i++;
	}
	ft_replace2(list_a, tab, size);
}
