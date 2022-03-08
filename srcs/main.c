/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:10:52 by jroux-fo          #+#    #+#             */
/*   Updated: 2022/03/08 17:19:45 by jroux-fo         ###   ########.fr       */
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

void	ft_isdigitandspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
		{
			if (str[i] != '-' && str[i] != '+' && str[i] != ' ')
			{
				printf("Error\n");
				exit(1);
			}
		}
		i++;
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
		if (argc == 2)
			ft_isdigitandspace(argv[i]);
		else
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

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_is_sorted(t_list *list)
{
	if (list->next == NULL)
	{
		printf("gg tout est trié\n");
		exit(0);
	}
	if (list->next->next == NULL)
	{
		if (list->value <= list->next->value)
		{
			printf("gg tout est trié\n");
			exit(0);
		}
		return ;
	}
	while (list->next->next)
	{
		if (list->next->value < list->value)
			return ;
		list = list->next;
	}
	if (list->next->value < list->value)
		return ;
	printf("gg tout est trié\n");
	exit(0);
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
		while (dest[i] != 0)
		{
			ft_lstadd_back(list, ft_lstnew(ft_atoi(dest[i])));
			free (dest[i]);
			i++;
		}
		free (dest[i]);
		free (dest);
		return ;
	}
	i++;
	while (argv[i])
	{
		ft_lstadd_back(list, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}

void	ft_print(int value)
{
	printf("%d ", value);
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

void	ft_push(t_list **send, t_list **receive)
{
	t_list	*temp;
	
	temp = *send;
	if (temp == NULL)
	{
		printf("Error\n");
		return ;
	}
	if (*receive == NULL)
	{
		*receive = ft_lstnew(temp->value);
		// receive->next = NULL;
		return ;
	}
	// while (send->next->next)
	// 	send = send->next;
	ft_lstadd_front(receive, temp);
	*send = (*send)->next->next;
	//	*send = (*send)->next;
}

// void	ft_push(t_list *send, t_list *receive)
// {
// 	if (send == NULL)
// 	{
// 		printf("Error\n");
// 		return ;
// 	}
// 	if (receive == NULL)
// 	{
// 		receive = ft_lstnew(send->value);
// 		receive->next = NULL;
// 		return ;
// 	}
// 	while (send->next->next)
// 		send = send->next;
// 	ft_lstadd_back(&receive, send->next);
// 	send->next = NULL;
// }

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

void	ft_rotate(t_list *list)
{
	int	temp;

	if (list == NULL || list->next == NULL)
		return ;
	temp = list->value;
	while (list->next)
	{
		list->value = list->next->value;
		list = list->next;
	}
	list->value = temp;
}

void	ft_sswap(t_list *list_a, t_list *list_b)
{
	ft_swap(list_a);
	ft_swap(list_b);
}

void	ft_rrotate(t_list *list_a, t_list *list_b)
{
	ft_rotate(list_a);
	ft_rotate(list_b);
}

void	ft_rreverse_rotate(t_list **list_a, t_list **list_b)
{
	ft_reverse_rotate(list_a);
	ft_reverse_rotate(list_b);
}

int	ft_duplicate(int *tab, int nb, int size)
{
	int i;

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

int	ft_mini(t_list **list, int *tab, int size)
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

void	ft_replace(t_list **list_a)
{
	t_list	*temp_a;
	int		*tab;
	int		i;
	int		size;
	int		mini;

	i = 1;
	temp_a = *list_a;
	size = ft_lstsize(temp_a);
	printf("size = %d\n", size);
	tab = malloc(sizeof(int) * size);
	mini = ft_mini(&temp_a, tab, size);
	tab[0] = mini;
	printf("tab[0] = %d\n", tab[0]);
	while (i < size)
	{
		mini = ft_mini(&temp_a, tab, size);
		tab[i] = mini;
		printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}
}

//////////////////////////////////////////////////////////////
///////////////////////ON TRIE LA/////////////////////////////
//////////////////////////////////////////////////////////////

void	ft_sort_3(t_list *list_a, t_list *list_b)
{
	(void)list_b;
	
	while (ft_is_sorted2(list_a) != 0)
	{
		if (list_a->value > list_a->next->value)
			ft_rotate(list_a);
		if (list_a->next->value > list_a->next->next->value)
			ft_swap(list_a);
	}
}

void	ft_big_sort(t_list **list_a, t_list **list_b)
{
	int		i;
	int		j;
	int		size;
	int		nb;

	size = ft_lstsize(*list_a);
	i = 0;
	j = 0;
	while (ft_is_sorted2(*list_a) != 0)
	{
		j = 0;
		while (j < size)
		{
			printf("salut\n");
			nb = (*list_a)->value;
			if ((nb >> i) & 1)
				ft_rotate(*list_a);
			else
				ft_push(list_a, list_b);
			j++;
		}
		while (list_b == NULL)
		{
			printf("salut\n");
			ft_push(list_b, list_a);
		}
		printf("salut\n");
		i++;
	}
}

// void	ft_sort(t_list **list_a, t_list **list_b)
// {
// 	t_list	*temp_a;
// 	t_list	*temp_b;

// 	temp_a = *list_a;
// 	temp_b = *list_b;
// 	if (ft_lstsize(temp_a) == 3)
// 		ft_sort_3(temp_a, temp_b);
// 	else if (ft_lstsize(temp_a) <= 5)
// 		printf("tri de 5\n");
// 	else
// 		printf("big_sort\n");
// }

//////////////////////////////////////////////////////////////
///////////////////////ON TRIE LA/////////////////////////////
//////////////////////////////////////////////////////////////

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	
	ft_error(argc, argv);
	list_a = ft_lstnew(ft_atoi(argv[1]));
	// list_b = ft_lstnew(ft_atoi(argv[1])); 
	list_b = NULL;
	
	ft_init_list(&list_a, argc - 1, argv);
	ft_is_sorted(list_a);
	// ft_init_list(&list_b, argc - 1, argv);
	printf("STACK A\n");
	ft_lstiter(list_a, ft_print);
	printf("\n");
	printf("/////////////////////////\n");
	printf("STACK B\n");
	ft_lstiter(list_b, ft_print);
	printf("\n");
	

	// ft_big_sort(&list_a, &list_b);
	// printf("finis\n");
	ft_replace(&list_a);
	// ft_push(&list_a, &list_b);
	// ft_rotate(list_a);


	
	// printf("\n\n\n\n\n");


	
	printf("STACK A\n");
	ft_lstiter(list_a, ft_print);
	printf("\n");
	printf("/////////////////////////\n");
	printf("STACK B\n");
	ft_lstiter(list_b, ft_print);
	printf("\n");
	// ft_rotate(list_a);
	// printf("/////////////////////////\n");
	// printf("/////////////////////////\n");
	// printf("/////////////////////////\n");
	// printf("STACK A\n");
	// ft_lstiter(list_a, ft_print);
	// printf("\n");
	// printf("/////////////////////////\n");
	// printf("STACK B\n");
	// ft_lstiter(list_b, ft_print);
	// printf("\n");
}
