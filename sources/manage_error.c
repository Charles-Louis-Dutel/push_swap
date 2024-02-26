/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:22:15 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/26 14:23:25 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int argc, char **argv, int i)
{
	int (j) = 0;
	if (argv[i] == NULL)
		return (1);
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '\0')
			return (1);
		while (argv[i][j])
		{
			if (!(argv[i][j] == '-' || argv[i][j] == '+' ||
			(argv[i][j] >= '0' && argv[i][j] <= '9')))
				return (1);
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				if (!(argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9'))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

long	ft_atoi_modif(const char *str)
{
	int			i;
	double		nb;
	int			sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -sign;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb *= sign;
	if (nb < -2147483648 || nb > 2147483647)
		return (11111111111);
	return ((long)nb);
}

static int	*pile_to_tab(int *tab, t_pile *pile)
{
	t_pile	*temp;
	int		i;

	temp = pile;
	i = 0;
	while (temp)
	{
		tab[i] = temp->nbr;
		i++;
		temp = temp->next;
	}
	return (tab);
}

int	check_doublons(t_pile *pile)
{
	int		len;
	int		i;
	int		j;
	int		*tab;

	len = pile_len(&pile);
	tab = malloc(sizeof(int) * len);
	tab = pile_to_tab(tab, pile);
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[j] == tab[i])
			{
				free(tab);
				return (1);
			}
			j++;
		}
		i++;
	}
	free(tab);
	return (0);
}

void	ft_le_xav(char **dest)
{
	size_t	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}
