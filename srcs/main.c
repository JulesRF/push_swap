/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:10:52 by jroux-fo          #+#    #+#             */
/*   Updated: 2022/02/16 14:22:18 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '9' || str[i] <= '0')
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
		ft_printf("%s\n", argv[i]);
		ft_isdigit(argv[i]);
		i++;
	}
}



int	main(int argc, char **argv)
{
	ft_error(argc, argv);
	ft_init_list(argc, argv);
}