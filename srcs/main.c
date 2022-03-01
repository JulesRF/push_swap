/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:10:52 by jroux-fo          #+#    #+#             */
/*   Updated: 2022/03/01 16:42:28 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include <stdio.h>

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
				printf("Error\n");
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
		printf("Error\n");
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

t_list	*ft_lstnew(int value)
{
	t_list	*newcell;

	newcell = malloc(sizeof(t_list));
	if (!newcell)
		return (NULL);
	newcell->value = value;
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
		ft_lstadd_back(&list, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}

void	ft_print(int value)
{
	printf("Value : %d\n", value);
}

void	ft_lstiter(t_list *list, void (*f)(int))
{
	while (list)
	{
		(*f)(list->value);
		list = list->next;
	}
}

void	ft_swap(t_list *list)
{
	int	temp;

	if (list == NULL || list->next == NULL)
	{
		printf("Error\n");
		return ;
	}
	while (list->next->next)
		list = list->next;
	// printf("%d\n", list->index);
	temp = list->value;
	list->value = list->next->value;
	list->next->value = temp;
}

void	ft_sswap(t_list *list_a, t_list *list_b)
{
	ft_swap(list_a);
	ft_swap(list_b);
}

void	ft_push(t_list *send, t_list *receive)
{
	if (send == NULL)
	{
		printf("Error\n");
		return ;
	}
	while (send->next->next)
		send = send->next;
	ft_lstadd_back(&receive, send->next);
	send->next = NULL;
}

void	ft_rotate(t_list **list)
{
	t_list	*temp;
	t_list	*last;

	temp = *list;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *list;
	(*list) = last;
}

void	ft_rrotate(t_list **list_a, t_list **list_b)
{
	ft_rotate(list_a);
	ft_rotate(list_b);
}

void	ft_reverse_rotate(t_list *list)
{
	int	temp;

	temp = list->value;
	while (list->next)
	{
		list->value = list->next->value;
		list = list->next;
	}
	list->value = temp;
}

void	ft_rreverse_rotate(t_list *list_a, t_list *list_b)
{
	ft_reverse_rotate(list_a);
	ft_reverse_rotate(list_b);
}

int	main(int argc, char **argv)
{
	t_list	*bottom_a;
	t_list	*bottom_b;
	
	ft_error(argc, argv);
	bottom_a = ft_lstnew(ft_atoi(argv[1]));
	bottom_a->next = NULL;
	bottom_b = ft_lstnew(ft_atoi(argv[1]));
	bottom_b->next = NULL;
	
	ft_init_list(bottom_a, argc, argv);
	ft_init_list(bottom_b, argc, argv);
	printf("STACK A\n");
	ft_lstiter(bottom_a, ft_print);
	printf("/////////////////////////\n");
	printf("STACK B\n");
	ft_lstiter(bottom_b, ft_print);
	ft_rreverse_rotate(bottom_a, bottom_b);
	printf("/////////////////////////\n");
	printf("/////////////////////////\n");
	printf("/////////////////////////\n");
	printf("STACK A\n");
	ft_lstiter(bottom_a, ft_print);
	printf("/////////////////////////\n");
	printf("STACK B\n");
	ft_lstiter(bottom_b, ft_print);
}
