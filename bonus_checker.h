/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:37:12 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/20 09:27:05 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CHECKER_H
# define BONUS_CHECKER_H

# include "push_swap.h"

void	swap_bonus(t_pile **pile);
void	push_bonus(t_pile **from, t_pile **to);
void	rotate_bonus(t_pile **pile);
void	rev_rotate_bonus(t_pile **pile);
void	rotate_all(t_pile **pile_a, t_pile **pile_b, const char *ins);

#endif
