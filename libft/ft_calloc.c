/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:48:46 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/08 11:45:40 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size == 0)
		return (malloc(0));
	if (nmemb > 2147483647 / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
int	main(void)
{
	int i;
	int * pointer = (int *) calloc( 10, sizeof(int) );
	for (i=0; i<10; i++ ) {
		printf( "%d ", pointer[i] );
	}
	printf( "\n" );
	for ( i=0; i<10-1; i++ ) {
		pointer[i] = i;
	}
	for (i=0; i<10; i++ ) {
		printf( "%d ", pointer[i] );
	}
	printf( "\n\n" );


	int *pointer2 = (int *) ft_calloc( 10, sizeof(int) );
	for (i=0; i<10; i++ )
		printf( "%d ", pointer2[i] );
	printf( "\n" );
	for ( i=0; i<10-1; i++ )
		pointer2[i] = i;
	for (i=0; i<10; i++ )
		printf( "%d ", pointer2[i] );
	printf( "\n" );

	free( pointer );
	free( pointer2 );
	return (0);
}*/
