/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:02:51 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/17 10:39:14 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct pile_elem
{
	int					nbr;
	struct pile_elem	*next;
}	t_pile;

/*Error management*/
int		check_args(int argc, char **argv);
long	ft_atoi_modif(const char *str);
int		check_doublons(t_pile *pile);

/*Pile management*/
t_pile	*new_pile(void);
void	push_pile(t_pile **pile, int nbr);
void	clear_pile(t_pile **pile);
void	pop_one(t_pile **pile);
t_pile	*new_elem(int nbr);

/*Utils*/
t_pile	*get_last(t_pile **pile);
int		pile_len(t_pile **pile);
void	print_pile(t_pile **pile);

/*Command*/
void	swap_a(t_pile **pile);
void	push_a(t_pile **from, t_pile **to);
void	rotate_a(t_pile **pile);
void	rev_rotate_a(t_pile **pile);
void	swap_b(t_pile **pile);
void	push_b(t_pile **from, t_pile **to);
void	rotate_b(t_pile **pile);
void	rev_rotate_b(t_pile **pile);
void	rotate(t_pile **pile_a, t_pile **pile_b);
void	rev_rotate(t_pile **pile_a, t_pile **pile_b);

/*Algo*/
void	choose_algo(t_pile **pile_a, t_pile **pile_b);
void	sort_pile(t_pile **pile_a, t_pile **pile_b);

/*Alog_utils*/
void	sort_help(t_pile **pile_a, t_pile **pile_b, int m_a, int m_b);
void	sort_help_b(t_pile **pile_b, int pos_inf);
void	sort_help_a(t_pile **pile_a, int pos_inf);
int		find_minimum(t_pile **pile);
int		find_maximum(t_pile **pile);

/*Find cheapest*/
int		find_cheapest(t_pile **pile_a, t_pile **pile_b);

/*Pile of 3*/
void	pile_of_3(t_pile **pile_a);
int		find_max_pos(t_pile **pile);
int		find_min_pos(t_pile **pile);

/*Pile of 5*/
void	pile_of_5(t_pile **pile_a, t_pile **pile_b);

#endif
