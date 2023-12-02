/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:02:51 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/02 03:30:06 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct pile_elem
{
	int					nbr;
	struct pile_elem	*next;
}	*t_pile;

/*Error management*/
int		check_args(int argc, char **argv);
long	ft_atoi_modif(const char *str);
int		check_doublons(t_pile pile);
/*Pile management*/
t_pile	new_pile(void);
int		is_pile_empty(t_pile pile);
t_pile	push_pile(t_pile pile, int nbr);
t_pile	clear_pile(t_pile pile);
void	print_pile(t_pile pile);
/*Utils*/
t_pile	get_last(t_pile pile);
int		pile_len(t_pile pile);

#endif
