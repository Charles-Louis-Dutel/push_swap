/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:37:12 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/01 16:53:35 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../push_swap.h"

/*Command_bonus*/
void	swap_bonus(t_pile **pile);
void	push_bonus(t_pile **from, t_pile **to);
void	rotate_bonus(t_pile **pile);
void	rev_rotate_bonus(t_pile **pile);
void	rotate_all(t_pile **pile_a, t_pile **pile_b, const char *ins);

#endif
