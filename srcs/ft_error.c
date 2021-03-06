/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:29:48 by jroux-fo          #+#    #+#             */
/*   Updated: 2022/03/18 15:14:32 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
		{
			if (str[i] != '-' && str[i] != '+')
			{
				ft_putstr("Error\n");
				exit(1);
			}
		}
		i++;
	}
}

void	ft_isdigitandspace(char *str)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
		{
			if (str[i] != '-' && str[i] != '+' && str[i] != ' ')
			{
				ft_putstr("Error\n");
				exit(1);
			}
		}
		else
			nb++;
		i++;
	}
	if (nb == 0)
	{
		ft_putstr("Error\n");
		exit(1);
	}
}

void	ft_same_digit2(char **argv, char **dest, int i, int j)
{
	dest = ft_split(argv[1], ' ');
	while (dest[i] != 0)
	{
		j = 0;
		if (ft_atoi(dest[i], dest, 2) > 2147483647)
		{
			ft_putstr("Error\n");
			ft_free_split(dest);
			exit(1);
		}
		while (dest[j] != 0)
		{
			if (ft_atoi(dest[i], dest, 2) == ft_atoi(dest[j], dest, 2)
				&& i != j)
			{
				ft_putstr("Error\n");
				ft_free_split(dest);
				exit(1);
			}
			j++;
		}
		i++;
	}
	ft_free_split(dest);
}

void	ft_same_digit1(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i], argv, 1) == ft_atoi(argv[j], argv, 1)
				&& i != j)
			{
				ft_putstr("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_error(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		exit(0);
	while (i < argc)
	{
		if (argc == 2)
			ft_isdigitandspace(argv[i]);
		else
		{
			ft_isdigit(argv[i]);
			if (ft_atoi(argv[i], argv, 1) > 2147483647)
				exit(1);
		}
		i++;
	}
	if (argc == 2)
		ft_same_digit2(argv, NULL, 0, 0);
	else
		ft_same_digit1(argc, argv);
}
