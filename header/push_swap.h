/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:42:32 by jroux-fo          #+#    #+#             */
/*   Updated: 2022/03/19 19:16:46 by jroux-fo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

//	ft_split.c
char		**ft_split(char const *s, char c);

//	ft_atoi.c
int			ft_whitespaces(const char *str);
int			ft_strcmp(const char *s1, char *s2);
void		ft_exit_atoi(char **dest, int argc);
int			ft_check(const char *nptr, char **dest, int argc);
int			ft_atoi(const char *nptr, char **dest, int argc);

//	ft_error.c
void		ft_isdigit(char *str);
void		ft_isdigitandspace(char *str);
void		ft_same_digit2(char **argv, char **dest, int i, int j);
void		ft_same_digit1(int argc, char **argv);
void		ft_error(int argc, char **argv);

//	ft_lst_utils.c
int			ft_lstsize(t_list *lst);
t_list		*ft_lstnew(int value);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstadd_front(t_list **alst, t_list *new);

//	ft_sort.c
void		ft_sort_3(t_list *list_a, t_list *list_b);
int			ft_smallest(t_list *list);
void		ft_small_sort(t_list **list_a, t_list **list_b, int size);
void		ft_big_sort(t_list **list_a, t_list **list_b, int size);
void		ft_sort(t_list **list_a, t_list **list_b);

//	ft_replace.c
int			ft_duplicate(long int *tab, int nb, int size);
int			ft_mini(t_list **list, long int *tab, int size);
void		ft_replace3(t_list **list, long int *src, int *dest, int size);
void		ft_replace2(t_list **list, long int *src, int size);
void		ft_replace(t_list **list_a);

//	ft_operation.c
int			ft_strlen(const char *s);
void		ft_swap(t_list *list, char wich);
void		ft_push(t_list **send, t_list **receive, char wich);
void		ft_reverse_rotate(t_list **list, char wich);
void		ft_rotate(t_list *list, char wich);

//	ft_operation2.c
void		ft_spe_52(t_list *temp_a, t_list *temp_b);
int			ft_spe_5(t_list **list_a, t_list **list_b, int size);
void		ft_sswap(t_list *list_a, t_list *list_b);
void		ft_rrotate(t_list *list_a, t_list *list_b);
void		ft_rreverse_rotate(t_list **list_a, t_list **list_b);

//	ft_utils.c
void		ft_putstr(char *str);
void		ft_free_split(char	**dest);
void		ft_lstclear(t_list **lst);
void		ft_exit(t_list **list, char *text, int end);
long int	*ft_init_tab(long int *tab, int size);

//	ft_init.c
void		ft_is_sorted(t_list **list, t_list *temp);
int			ft_is_sorted2(t_list *list);
void		ft_init_list(t_list **list, int argc, char **argv);

//	main.c
int			main(int argc, char **argv);

#endif