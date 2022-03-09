/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:42:32 by jroux-fo          #+#    #+#             */
/*   Updated: 2022/03/09 16:06:23 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_list
{
	int	value;
	struct s_list	*next;
}					t_list;

//	ft_split.c
char	**ft_split(char const *s, char c);

//	ft_atoi.c
int	ft_atoi(const char *nptr);

#endif