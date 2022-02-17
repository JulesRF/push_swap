/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:10:52 by jroux-fo          #+#    #+#             */
/*   Updated: 2022/02/17 18:15:03 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
				ft_printf("Error\n");
				exit(1);
			}
		}
		i++;
	}
}

void	ft_error(int argc, char **argv)
{
	int	i;
	
	i = 1;
	if (argc == 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	while (i < argc)
	{
		// ft_printf("%s\n", argv[i]);
		ft_isdigit(argv[i]);
		i++;
	}
}

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

t_list	*ft_lstnew(int value, int index)
{
	t_list	*newcell;

	newcell = malloc(sizeof(t_list));
	if (!newcell)
		return (NULL);
	newcell->value = value;
	newcell->index = index;
	newcell->next = NULL;
	return (newcell);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	temp = ft_lstlast(*alst);
	temp->next = new;
}

void	ft_init_list(t_list *list, int argc, char **argv)
{
	int	i;

	i = 2;
	while (i < argc)
	{
		ft_lstadd_back(&list, ft_lstnew(ft_atoi(argv[i]), i - 1));
		i++;
	}
}

void	ft_print(int value, int index)
{
	ft_printf("Index : %d ", index);
	ft_printf("Value : %d\n", value);
}

void	ft_lstiter(t_list *lst, void (*f)(int, int))
{
	while (lst)
	{
		(*f)(lst->value, lst->index);
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*bottom;
	
	ft_error(argc, argv);
	bottom = ft_lstnew(ft_atoi(argv[1]), 0);
	bottom->next = NULL;
	ft_init_list(bottom, argc, argv);
	ft_lstiter(bottom, ft_print);
}