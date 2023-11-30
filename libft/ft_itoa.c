/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:24:05 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/12 10:25:43 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putnbr_in_tab(char *tab, long n, int i)
{
	if (n < 0)
	{
		tab[0] = '-';
		n = -n;
		i++;
	}
	if (n <= 9)
	{
		tab[i] = n + '0';
		i++;
	}
	if (n > 9)
	{
		i--;
		ft_putnbr_in_tab(tab, (n / 10), i);
		i++;
		ft_putnbr_in_tab(tab, (n % 10), i);
	}
	return (tab);
}

static int	ft_size_tab(int n)
{
	int		a;
	int		i;

	i = 0;
	if (n == 0)
		i = 1;
	else
	{
		a = n;
		while (a != 0)
		{
			a /= 10;
			i++;
		}
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		i;

	i = ft_size_tab(n);
	if (n < 0)
		tab = (char *)malloc(sizeof(char) * (i + 2));
	else
		tab = (char *)malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	ft_putnbr_in_tab(tab, n, i - 1);
	if (n < 0)
		i++;
	tab[i] = '\0';
	return (tab);
}
/*
int main()
{
	char *tab = ft_itoa(-2);
	int i = 0;
	__builtin_printf("%s\n", tab);
	while (i < 14)
	{
		__builtin_printf("%c\n", tab[i]);
		i++;
	}
	return 0;
}*/
