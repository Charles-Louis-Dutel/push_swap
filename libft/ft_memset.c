/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:04:47 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/12 10:39:11 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			*str;
	unsigned long	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
/*
int	main(void) {

	char a[8] = "bonjour";
	char c[8] = "bonjour";
	//int tab [] = { 54, 85, 20, 63, 21 };
	//int array [] = { 54, 85, 20, 63, 21 };
	size_t size = sizeof(char) * 5;
	int length;

	for( length=0; length<7; length++)
	{
		printf( "%c ", c[ length ] );
	}
	printf( "\n" );
	memset( c, 45, size );
	for( length=0; length<7; length++)
	{
		printf( "%c ", c[ length ] );
	}
	printf( "\n\n" );




	for( length=0; length<7; length++)
	{
		printf( "%c ", a[ length ] );
	}
	printf( "\n" );
	ft_memset(a, 45, size );
	for( length=0; length<7; length++)
	{
		printf( "%c ", a[ length ] );
	}
	printf( "\n" );
	return (0);
}*/
