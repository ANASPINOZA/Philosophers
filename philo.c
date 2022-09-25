/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:42:42 by aadnane           #+#    #+#             */
/*   Updated: 2022/09/25 11:43:21 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int i = 0;

void	*ft_sbardila(void *t)
{
	int *j = (int*)t;
	int k = *j;
	printf ("t %d\n", k);
	while (i < 1000000)
	{
		printf("ft_i : %d\n", i);
		i += 1;
	}
	return (NULL);
}


// eating sleep think


int main()
{
	int		j;
	pthread_t new_thread[5];

	j = 0;
	printf("i1: %d\n", i);
	while (j < 5)
	{
		pthread_create (&new_thread[j], NULL, &ft_sbardila, &j);
		pthread_join (new_thread[j], NULL);
		//usleep (100);
		j++;
	}
	printf("i2: %d\n", i);
	return (0);
}