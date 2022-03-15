/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:04:28 by jroux-fo          #+#    #+#             */
/*   Updated: 2022/03/15 14:57:22 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_whitespaces(const char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	while (str[i + j] == '-' || str[i + j] == '+')
		j++;
	if (j > 1)
		return (-1);
	return (i);
}

int	ft_strcmp(const char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_exit_atoi(char **dest, int argc)
{
	if (argc == 2)
	{
		ft_free_split(dest);
		ft_putstr("Error\n");
		exit(1);
	}
	ft_putstr("Error\n");
	exit(1);
}

int	ft_check(const char *nptr, char **dest, int argc)
{
	if (ft_strcmp(nptr, "2147483647") > 0
		&& ft_strlen (nptr) >= ft_strlen("2147483647"))
		ft_exit_atoi(dest, argc);
	else if (ft_strcmp(nptr, "-2147483648") > 0
		&& ft_strlen (nptr) >= ft_strlen("-2147483648"))
		ft_exit_atoi(dest, argc);
	else if (ft_strcmp(nptr, "2147483647") == 0)
		return (2147483647);
	return (2);
}

int	ft_atoi(const char *nptr, char **dest, int argc)
{
	int	res;
	int	i;
	int	moins;

	if (ft_check(nptr, dest, argc) != 2)
		return (ft_check(nptr, dest, argc));
	res = 0;
	i = ft_whitespaces(nptr);
	if (i == -1)
		ft_exit_atoi(dest, argc);
	moins = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			moins = 1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	if (moins == 1)
		return (-res);
	return (res);
}
