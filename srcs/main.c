/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:10:52 by jroux-fo          #+#    #+#             */
/*   Updated: 2022/03/14 18:23:21 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	ft_error(argc, argv);
	list_a = NULL;
	list_b = NULL;
	ft_init_list(&list_a, argc - 1, argv);
	ft_is_sorted(&list_a, list_a);
	ft_replace(&list_a);
	ft_sort(&list_a, &list_b);
	ft_lstclear(&list_a);
	ft_lstclear(&list_b);
}
