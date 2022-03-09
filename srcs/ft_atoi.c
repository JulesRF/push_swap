/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:04:28 by jroux-fo          #+#    #+#             */
/*   Updated: 2022/03/09 16:05:26 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_whitespaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
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

int	ft_check(const char *nptr)
{
	if (ft_strcmp(nptr, "2147483647") > 0
		&& ft_strlen (nptr) >= ft_strlen("2147483647"))
		return (-1);
	else if (ft_strcmp(nptr, "-2147483648") > 0
		&& ft_strlen (nptr) >= ft_strlen("-2147483648"))
		return (0);
	return (2);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	i;
	int	moins;

	if (ft_strcmp(nptr, "2147483647") == 0)
		return (2147483647);
	if (ft_check(nptr) != 2)
		return (ft_check(nptr));
	res = 0;
	i = ft_whitespaces(nptr);
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